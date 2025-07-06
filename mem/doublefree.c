// trigger a double free bug. then fix it.

#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(){
  int nums[N] = {0, 1, 2, 3, 4};
  int* memnums = (int*) malloc(N * sizeof(int));

  for (int i = 0; i < N; i++){
    memnums[i] = nums[N - 1 - i];
  }
  for (int i = 0; i < N; i++){
    printf("%i", memnums[i]);
  }

  free(memnums);
  // free(memnums); // compiles but throws an error upon running. fixed by commenting out
}
