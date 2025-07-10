#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define THREAD_COUNT 8

int count = 0;
pthread_rwlock_t lock;

void* func(void* arg){
  int thread = *(int*) arg;

  while (1) {
    if (thread == 0) {
      // WRITER thread
      pthread_rwlock_wrlock(&lock);
      if (count >= 10000) {
        pthread_rwlock_unlock(&lock);
        break;
      }
      count++;
      printf("thread %d incremented to %d\n", thread, count);
      pthread_rwlock_unlock(&lock);
    } else {
      // READER threads
      pthread_rwlock_rdlock(&lock);
      if (count >= 10000) {
        pthread_rwlock_unlock(&lock);
        break;
      }
      printf("current thread is %d, count is %d\n", thread, count);
      pthread_rwlock_unlock(&lock);
    }
  }

  return NULL;
}

int main(){
  pthread_t threads[THREAD_COUNT];
  int thread_ids[THREAD_COUNT];

  pthread_rwlock_init(&lock, NULL);

  for (int i = 0; i < THREAD_COUNT; i++) {
    thread_ids[i] = i;
    if (pthread_create(&threads[i], NULL, func, &thread_ids[i]) != 0){
      perror("thread creation error");
      exit(-1);
    }
  }

  for (int i = 0; i < THREAD_COUNT; i++) {
    pthread_join(threads[i], NULL);
  }

  pthread_rwlock_destroy(&lock);

  return 0;
}
