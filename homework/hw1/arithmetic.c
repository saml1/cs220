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

  }

  /*if(scanf(" %c %f", &operator, &addend) == 1){

    isvalid = 0;
    printf("malformed expression\n");

    }*/
  
  while(scanf(" %c %f", &operator, &addend) == 2 && isvalid == 1){
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

      }else {

	product /= addend;

      }

    } else {

      printf("malformed expression\n");
      isvalid = 0;

    }

    /*if(scanf(" %c %f", &operator, &addend) == 1){

      isvalid = 0;
      printf("malformed expression\n");

      }*/
    
  }
  //printf("%c", operator);
  //printf("%f", &addend);
  if(operator != 0 && whileloop == 0){

    printf("malformed expression\n");
    isvalid = 0;

  }
  
  /*if(scanf(" %c", &operator) == 1){

    isvalid = 0;
    printf("malformed expression\n");

    }*/
  
  if(isvalid == 1){

    printf("%f\n", product);

  }

}
