#include <stdio.h>


// returning size_t because strings can be very long
size_t my_strlen(char* string){
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

int main(){
  char* hi = "hi";
  char* longtest = "hihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihi";
  char* null = NULL;
  printf("size of first test %zd\n", my_strlen(hi)); 
  printf("size of long test %zd\n", my_strlen(longtest));
  printf("size of null test %zd\n", my_strlen(null));
}
