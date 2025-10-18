#include <string.h> // default strcpy and strlen
#include <stdio.h> // for printf

void my_strcpy(char* str1, char* str2){
  if (!str1 || !str2){
    printf("use valid strings");
  }

  // TODO: str2 prints a lot of "l"s, look into it and make this work properly
  for (int i = 0; i < strlen(str1); i++){
    str2[i] = str1[i];
  }
}

int main(){
  char strone[20] = "hello world";
  char strtwo[20] = "test";

  printf("strtwo before strcpy = %s\n", strtwo);
  strcpy(strtwo, strone);
  printf("strtwo after strcpy = %s\n", strtwo);

  char str1[20] = "hello world1";
  char str2[20] = "test2";
  printf("str2 before my strcpy = %s\n", str2);
  my_strcpy(str1, str2);
  printf("str2 after my strcpy = %s\n", str2);
}
