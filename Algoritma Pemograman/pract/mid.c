#include <stdio.h>

void menu(){
  printf("---------------------------------------\n");
  printf("Programmer    : Muhammad Faiz Silmi\n");
  printf("Program       : Student Grade Calculator\n");
  printf("---------------------------------------\n");
}


int main(){
  int math, eng, sc, avarage;

  menu();
  
  printf("Input math score: \n");
  scanf("%d", &math);
  printf("Input english score: \n");
  scanf("%d", &eng);
  printf("Input science score: \n");
  scanf("%d", &sc);

  avarage = (math + eng + sc)/3;

  if(avarage >= 80){
    printf("The avarage score is: %d (pass)", avarage);
  } else{
    printf("The avarage score is: %d (fucking loser)", avarage);
  }
}