/*
build a tiny function that allocates memory repeatedly without freeing.
use leaks or valgrind to prove the leak.
*/

#include <stdlib.h>
#include <stdio.h>

// i can create space in memory then constantly reallocate it with realloc

int main(){
  int* random = (int*) malloc(5);

  for (int i = 0; i < 9999; i++){
    int* temp = realloc(random, 5 + i);
    printf("allocated temp");
    if (temp == NULL){
      perror("error while reallocating");
      exit(-1);
    }
    random = temp;
    printf("allocated to random");
  }

  // proof of leak
  /*
  leaks Report Version: 4.0, multi-line stacks
Process 59411: 187 nodes malloced for 24 KB
Process 59411: 1 leak for 10240 total leaked bytes.

STACK OF 1 INSTANCE OF 'ROOT LEAK: <realloc in main>':
3   dyld                                  0x19a7f4274 start + 2840
2   memleak                               0x1002e3ec0 main + 84  memoryleaksim.c:15
1   libsystem_malloc.dylib                0x19a9af5a4 _realloc + 468
0   libsystem_malloc.dylib                0x19a9aed88 _malloc_zone_realloc + 144
====
    1 (10.0K) ROOT LEAK: <realloc in main 0x13f00c200> [10240]
  */

}
