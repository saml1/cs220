#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// this function takes a message in binary form (i.e., a message that only includes
// 0s and 1s) as a string and returns decimal equivalent of it as an integer.
// Example: string message "111101" return 61 as an int, since 61 is decimal
// equivalent of "111101".  
int str_to_int(char msg[], int len) {
  int val = 0;
  for(int i = 0; i < len; i++){
    int temp = 0;
    if(msg[len-1-i] == '1'){
      temp = 1;
      for(int k = 0; k < i; k++){
	temp *= 2;
      }
      val += temp;
    }
  }
  return val;

}


// this function takes a decimal value as an integer and creates a string
// including 0s and 1s that is the binary representation of the integer number.
// Example: number 61 (as an int) results in "111101", since "111101" is
// binary representation of the decimal value 61.  
void int_to_str(int num_encrypted, char msg_encrypted[], int len) {
  int temp = num_encrypted;
  for(int i = 0; i < len-1; i++){
    int pow = 1;
    for(int j = 0; j < len - 1 - i; j++){
      pow*= 2;
    }
    if(temp > pow){
      //printf("here\n");
      msg_encrypted[i] = '1';
      temp -= pow;
    }else{
      msg_encrypted[i] = '0';
    }
  }
  if(temp ==1){
    msg_encrypted[len-1] = '1';
  }
  //msg_encrypted[len] = 
  // TODO: FINISH IMPLEMENTATION

}


int main() {
  //printf("%d\n", str_to_int("111101",6));
  //char msg[7];
  //printf("%s\n", msg);
  //printf("%s\n", msg);
  //int_to_str(123, msg, 7);
  //printf("%s\n", msg);

  int num_msg = 0; // the binary message as an int
  char msg[33] = {'\0'}; // this will hold the binary message as a string
  int n = -1; // n used in encryption

  printf ("Enter the message to be encrypted in binary format (max 32 bit): ");
  if (scanf(" %s", msg) != 1) { // read the binary message as a string
    printf("Could not read the message!\n");
    return 1;
  }  

  int len = strlen(msg); // length of the binary message
  
  // convert the string binary message to an integer
  num_msg = str_to_int(msg, len);
  
  // read n
  //printf("%d\n", num_msg);
  printf ("Enter n: ");
  if (scanf("%d", &n) != 1) {
    printf("Could not read n!\n");
    return 1;
  }

  int num_encrypted = num_msg;

  // TODO: NOW PERFORM THE ENCRYPTION BY SHIFTING "msg" n - 1
  // TIMES AND XORING THE CORRESPONDING COLUMNS 

  //char temp[33] = {'\0'};

  /*for(int i = 1; i < n; i++){
    for(int j = 0; j < len; j++){
      temp[j] = (char)((int)msg[j] ^(int) msg[j] << i);
    }
    }*/

  //int temp = 0;
  int list[n];
  for(int i = 0; i < n; i++){
    list[i] = num_msg << i;
    //temp = (num_encrypted <<  i) ^ (num_encrypted ^ (i-1));
    //temp = num_encrypted ^ temp;
  }
 
  for(int i = 1; i < n; i++){
    list[i] = list[i]^list[i-1]; 
    //printf("%dee\n", list[i]);
  }
  char msg_encrypted[33] = {'\0'};
  num_encrypted = list[n-1];
  int encrypted_len = len + n - 1;

  // convert the encrypted message back to a string
  int_to_str(num_encrypted, msg_encrypted, encrypted_len);

  // print out the original and encrypted messages as strings
  printf("Plain binary message is %s and encrypted message is %s \n", msg, msg_encrypted);
  return 0;

}
