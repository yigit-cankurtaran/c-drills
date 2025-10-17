#include <stdio.h>

// returning size_t because strings can be very long
size_t my_strlen(const char* string){ // const here to not modify the data the pointer points to
  // handle null pointer
  if (!string) return 0;

  // iterate through string to get size
  size_t str_size = 0;
  while (string[str_size] != '\0') { // '\0'=null term
    str_size++;
  }

  // no need to divide by sizeof(char), that's always 1
  return str_size;
}

size_t strlen_with_pointers(const char *s){
  if (!s) return 0;

  const char *p = s;
  while (*p) p++;
  return p - s;
}

int main(){
  char* hi = "hi";
  char* longtest = "hihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihi";
  char* null = NULL;
  printf("size of first test %zd\n", my_strlen(hi)); 
  printf("size of long test %zd\n", my_strlen(longtest));
  printf("size of null test %zd\n", my_strlen(null));

  printf("pointer test of first %zd\n", strlen_with_pointers(hi));
  printf("pointer test of long test %zd\n", strlen_with_pointers(longtest));
  printf("pointer test of null test %zd\n", strlen_with_pointers(null)); // segfaulted
}
