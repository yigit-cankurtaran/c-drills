#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int count = 0;
pthread_mutex_t locker;

void* increment (void* arg){
  int num = *(int*) arg;

  while (1){
   pthread_mutex_lock(&locker);
   if (count >= 10000) {
     pthread_mutex_unlock(&locker);
     break; // break loop if we hit 10000, reversing the check
   }

   count++;
   printf("thread %d: count is %d\n", num, count);
   pthread_mutex_unlock(&locker);
  }

  return NULL;
 }

 int main(){
   int thread_count = 8;
   int thread_ids[thread_count];
   pthread_t threads[thread_count];

   if (pthread_mutex_init(&locker, NULL) != 0){
     perror("mutex init failed\n");
     exit(-1);
   }
 
   for (int i = 0; i < thread_count; i++){
     thread_ids[i] = i;
     int create = pthread_create(&threads[i], NULL, increment, &thread_ids[i]);
     // sneaky bug, if we pass &i they all read a different number
     if (create != 0){
       perror("error during thread creation\n");
       exit(-1);
     }
   }

   for (int i = 0; i < thread_count; i++){
     pthread_join(threads[i], NULL);
   }

   pthread_mutex_destroy(&locker);

   return 0;
 }
