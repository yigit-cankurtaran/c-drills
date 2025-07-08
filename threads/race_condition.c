#include <pthread.h>
#include <stdio.h>

int count = 0;

void* increment (void* arg){
  int num = *(int*) arg;
  while (count < 10000){
    count++;
    printf("thread %d: count is %d\n", num, count);
  }

  return NULL;
 }

 int main(){
   int thread_count = 8;
   int thread_ids[thread_count];
   pthread_t threads[thread_count];

   for (int i = 0; i < thread_count; i++){
     thread_ids[i] = i;
     pthread_create(&threads[i], NULL, increment, &thread_ids[i]);
     // sneaky bug, if we pass &i they all read a different number
   }

   for (int i = 0; i < thread_count; i++){
     pthread_join(threads[i], NULL);
   }

   // threads working at pretty much random
   // race condition, we'll use a mutex to fix this later on
 }
