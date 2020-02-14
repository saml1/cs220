#include <stdio.h>
#include "funs.h"

int main(){

  //printf("%d", abs(-2));
  printf("Enter a whole number that you wanna know the abs of\n");
  int num = 0;
  scanf("%d", &num);
  printf("The absolute value of %d is %d.", num, abs(num));
  
}
