//Ex2-1: gpa_simple.c

/* The purpose of this program is to compute GPAs for simple letter
   grades - no +/-, only A, B, C, D, F. Credits may be rational
   numbers.  Also determine and display notices for Dean's List
   (>=3.5) and Academic Probation (< 2.0).

SAMPLE RUN:

Welcome to the GPA calculator!
Enter grade and credits for each course below (ctrl-d to end):
course 1: A 4.0
course 2: b 2.7
course 3: B 3.5
course 4: c 3.0
course 5: f 1
course 6: a 3
course 7: 
Your GPA is 3.06

-----
PSEUDOCODE:

point_sum gets 0
credit_sum gets 0
points gets 0
gpa gets 0

display “Welcome to GPA calculator!”
prompt for list of grade/credits pairs

count gets 1
display "course #", count

repeat while there is a grade and credits to read
    convert grade to points
    add points * credits to point_sum
    add credits to credit_sum
    add 1 to count
    display "course #", count

if credit_sum > 0
   set gpa to point_sum / credit_sum
   display "GPA is ", gpa
   if gpa >= 3.5
      display "Dean's List"
   otherwise if gpa <= 2.0
      display "Uh-oh, Academic Probation..."
otherwise
   display "No credits attempted; no GPA to report"

*/


#include <stdio.h>

int main() {

  double point_sum = 0;
  double  credit_sum = 0;
  int points = 0;
  double gpa = 0;
  
  printf("Welcome to the GPA calculator!\nEnter grade and credits for each course below (ctrl-d to end):\n");

  int count = 1;
  char addend;
  printf("Course #%d: ", count);
  
  while(scanf("%c", &addend) == 1){
    getchar();
    switch(addend){
    case 'a': points = 4;
      break;
    case 'A': points = 4;
      break;
    case 'b': points = 3;
      break;
    case 'B': points = 3;
      break;
    case 'c': points = 2;
      break;
    case 'C': points = 2;
      break;
    case 'd': points = 1;
      break;
    case 'D': points = 1;
      break;
    case 'f': points = 0;
      break;
    case 'F': points = 0;
      break;
    }
    double credits = 0;
    scanf("%lf", &credits);
    getchar();
    point_sum += credits * points;
    credit_sum += credits;
    count += 1;
    printf("Course #%d: ", count);
    
    //printf("%d", point_sum);
    //printf("%d", credits);
    //sum +=addend;
    //numCourses+=1;
    }

  if(credit_sum > 0){
    gpa = point_sum / credit_sum;
    printf("GPA is %.2lf\n", gpa);
    if(gpa >= 3.5){
      printf("Dean's List");
    }else if (gpa <= 2.0){
      printf("Uh-oh, Academic Probation...");
    }
  }else{
    printf("No credits attempted; no GPA to report");
  }
  
  //TO DO: add your code here so that your program
  //produces output that would be identical to the
  //given sample run when provided the same input
  
 return 0;
}
