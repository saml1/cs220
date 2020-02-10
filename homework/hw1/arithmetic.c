//Sam Lipschitz                                                                 
//slipsch3                                                                      

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {

  printf("Please enter an arithmetic expression using * and / only:\n");
  float product = 1.0;
  float addend = 0;
  char operator = 0;
  int isvalid = 1;
  int whileloop = 0;
  
  if(scanf(" %f", &addend) == 1){

    product = addend;
    /* if(scanf(" %c %f", &operator, &addend) == 1){

      isvalid = 0;
      printf("malformed expression\n");

      }*/

  } else {

    printf("malformed expression\n");
    isvalid = 0;
    return 1;

  }


  
  while(isvalid == 1 && scanf(" %c %f", &operator, &addend) == 2){
    whileloop = 1;
    //printf(" %c %f ok\n", operator, addend);
    if(operator == '*'){

      product *=addend;
      //printf("%f", product);

    } else if (operator == '/'){

      //printf("test");

      if (addend == 0){

	printf("division by zero\n");
	isvalid = 0;
	return 2;

      }else {

	product /= addend;

      }

    } else {

      printf("malformed expression\n");
      isvalid = 0;
      return 1;
      
    }

    /*if(scanf(" %c %f", &operator, &addend) == 1){

      isvalid = 0;
      printf("malformed expression\n");

      }*/
    
  }
  //printf("%c", operator);
  //printf("%f", &addend);
  if(isvalid == 1 && operator != 0 && whileloop == 0){

    printf("malformed expression\n");
    isvalid = 0;
    return 1;

  }

  
  
  if(isvalid == 1 && scanf(" %c", &operator) == 1 && whileloop == 1){

    isvalid = 0;
    printf("malformed expression\n");
    return 1;

    }
  
  if(isvalid == 1){

    printf("%f\n", product);

  }

}
