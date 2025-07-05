/*
allocate memory for a string
copy content from a literal (e.g. "hello")
and modify it.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
  char var[5] = "hello";
  printf("printing from string: %s\n", var);

  int new_size = 50;
  char* new = (char*) malloc(new_size + 1); // leaving a +1 for the null terminator

  int old_size = sizeof(var);
  for (int i = 0; i < new_size / old_size; i++) {
    memcpy(new + i * old_size, var, old_size);
    // new and var are both pointers to their strings
    // advancing new anytime we add from var so we can keep copying
    // if we don't advance it it only prints "hello"
    }

  printf("printing from malloc: %s\n", new);

  free(new);
}
