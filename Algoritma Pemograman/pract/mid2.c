#include<stdio.h>

float celciustofahrenheit(int celcius) {
  return (celcius * 9 / 5) + 32;
}
float fahrenheittocelcius(int fahrenheit){
  return (fahrenheit - 32) * 5 / 9;
}

int main(){
  int choice;
  float temp, convTemp;

  printf("Temp Converter\n");
  printf("1. celcius to fahrenheit\n");
  printf("2. farenheit to celcius\n");
  printf("Input your choice: ");
  scanf("%d", &choice);

  switch (choice)
  {
  case 1:
    printf("Enter Celcius: ");
    scanf("%f", &temp);

    convTemp = celciustofahrenheit(temp);

    printf("Temp in fahrenheit: %.2f\n", convTemp);
    break;
  case 2:
    printf("Enter fahrenheit: ");
    scanf("%f", &temp);

    convTemp = fahrenheittocelcius(temp);

    printf("Temp in celcius: %.2f", convTemp);
    break;
  default:
  printf("Invalid choice!");
    break;
  }
}