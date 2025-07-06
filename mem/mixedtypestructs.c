/*
create a struct with mixed-type members.
print sizeof(struct) and analyze where padding is added.
*/

#include <stdio.h>

struct myStruct{
  int aNum;
  char aChar;
};

int main(){
  struct myStruct s1;
  s1.aChar = 'a';
  s1.aNum = 1;

  printf("%i\n", s1.aNum);
  printf("%c\n", s1.aChar);
  // confirmed existing

  printf("size of int is %lu\n", sizeof(int)); // prints 4
  printf("size of char is %lu\n", sizeof(char)); // prints 1
  printf("size of s1 is %lu\n", sizeof(s1)); // prints 8

  // the sizes not adding up is due to padding. aChar is padded in memory to match aNum.
}
