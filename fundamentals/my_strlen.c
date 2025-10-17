#include <stdio.h>

int my_strlen(char* string){
  // iterate through string to get size
  size_t str_size = 0;
  while (string[str_size] != '\0') { // '\0'=EOF
    str_size++;
  }

  return str_size / sizeof(char);
}

int main(){
  char* hi = "hi";
  char* longtest = "hihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihihi";
  printf("size of first test %d\n", my_strlen(hi));
  printf("size of long test %d\n", my_strlen(longtest));
}
