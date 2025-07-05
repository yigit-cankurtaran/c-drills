#import <stdlib.h>
#import <stdio.h>


int main(){
  int num_of_vals = 50;
  int* ptr = malloc(num_of_vals * sizeof(int));
  // filling with values
  for (int i = 0; i < num_of_vals; i++){
      ptr[i] = i + 5;
      printf("number %i is %i\n", i, ptr[i]);
  }
  printf("size of pointer is %lu\n", sizeof(ptr)); // returns the size of the pointer object
  free(ptr);
}
