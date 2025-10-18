#include <string.h> // to test actual strcpy
#include <stdio.h> // for printf

int main(){
  char str1[20] = "hello world";
  char str2[20] = "test";

  printf("str2 before strcpy = %s\n", str2);
  strcpy(str2, str1);
  printf("str2 after strcpy = %s\n", str2);
}
