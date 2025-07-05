#include <stdio.h>

int* localret(){
  int localvar = 5;
  int* localpoint = &localvar;

  return localpoint;
}


int main(){
  int* result = localret();
  printf("localpoint is %p\n", result);
  printf("value of localpoint is %i\n", *result);
}

// localret address constantly changes, the value is always 1
// the issue is localvar is a local, non-static variable, only exists in its function
// when we try dereferencing it it's undefined behavior, it no longer exists.
