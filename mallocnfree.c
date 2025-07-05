#import <stdlib.h>
#import <stdio.h>


int main(){
  int num_of_vals = 10;
  int* ptr = malloc(num_of_vals * sizeof(int));
  // filling with values
  for (int i = 0; i < num_of_vals; i++){
      ptr[i] = i + 5;
      printf("first ptr number %i is %i\n", i, ptr[i]);
  }
  printf("size of pointer is %lu\n", sizeof(ptr)); // returns the size of the pointer object

  int new_vals = 2 * num_of_vals;
  int* temp = realloc(ptr, new_vals * sizeof(int));
  if (temp == NULL) {
    perror("error reallocating memory");
    exit(-1);
  }
  ptr = temp;

  for (int i = 0; i < new_vals; i++){
      ptr[i] = i * 2;
      printf("second ptr number %i is %i\n", i, ptr[i]);
  }
  
  free(ptr);
}
