#include <pthread.h>
#include <stdio.h>

void* message(void* arg){
  int num = *(int*)arg;
  printf("created thread %d\n", num);
  return NULL;
}

int main(){
  pthread_t threads[5];
  int thread_count[5];

  for (int i = 0; i < 5; i++){
    thread_count[i] = i;
    pthread_create(&threads[i], NULL, message, &thread_count[i]);
  }

  for (int i = 0; i < 5; i++){
    pthread_join(threads[i], NULL);
  }

  return 0;
}

