#include <stdio.h>
#include <string.h>
#include "string_functions.h"

int concat(const char word1[], const char word2[], char result[], int result_capacity){

  //printf("%lu", strlen(word1) + strlen(word2));                                              
  if((int)(strlen(word1) + strlen(word2)) <= result_capacity){
    printf("I'm differenter");
    //printf("%lu", strlen(word2));                                                              
    for(int i = 0; i < (int)strlen(word1); i++){

      result[i] = word1[i];
      //printf("%c", result[i]);                                                                 

    }

    for (int j = 0; j < (int)strlen(word2); j++){

      result[j+ strlen(word1)] = word2[j];
      //printf("%c", word2[j]);                                                                  


    }

    result[(int)strlen(word1)+(int)strlen(word2)] = '\0';

  } else {

    return 1;

  }
   //TODO: replace the following stub with a correct function body so that                       
   //      this function behaves as indicated in the comment above                               
   //                                                                                            
   //NOTE: you may not use the strcat or strcpy library functions in your solution!              
   return 0;

}
