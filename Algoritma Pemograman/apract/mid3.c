#include<stdio.h>

#define MAX_STUDENTS 100


void input(int *stotal, char studentnames[MAX_STUDENTS][20]){

  printf("\nInput the number of students: \n");
  scanf("%d", stotal);

  for(int i = 0; i < *stotal; i++){
    printf("Enter name of student %d: ", i + 1);
    scanf("%s", studentnames[i]);
  }
}

void process(int stotal, char studentnames[MAX_STUDENTS][20], float grades[MAX_STUDENTS], float *average){
  float sum = 0.0;

  for(int i = 0; i < stotal; i++){
    printf("Enter grade for %s: ", studentnames[i]);
    scanf("%f", &grades[i]);
    sum += grades[i];
  }
  *average = sum / stotal;
}

void result(int stotal, char studentnames[MAX_STUDENTS][20], float grades[MAX_STUDENTS], float average){
  printf("\nStudent Grades:\n");
    for (int i = 0; i < stotal; i++) {
        printf("Student %s: %.2f\n", studentnames[i], grades[i]);
    }
    printf("Average grade: %.2f\n", average);
}
int main(){

int stotal;
char studentnames[MAX_STUDENTS][20];
float average;
float grades[100];

  input(&stotal, studentnames);
  process(stotal, studentnames, grades, &average);
  result(stotal, studentnames, grades, average);
  
  return 0;
}