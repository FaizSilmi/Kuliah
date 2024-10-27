#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void judul(){
  printf("==============================\n");
  printf("Nama    : Muhammad Faiz Silmi\n");
  printf("NIM     : 24343099\n");
  printf("Program : kalkulator sederhana\n");
  printf("==============================\n");
}

double tambah(double a, double b){
  return a + b;
}

double kurang(double a, double b){
  return a - b;
}
double kali(double a, double b){
  return a * b;
}
double bagi(double a, double b){
  return a / b;
}
double pangkat(double a, double b){
  return pow(a, b);
}
double kalkulator(double angka1, char operator, double angka2){
  double hasil;
  
}

int main(){
  double angka1, angka2, hasil;
  char operator;

  judul();

  printf("Masukkan operasi dan angka (3 + 4): ");
  scanf("%lf %c %lf", &angka1, &operator, &angka2);
  switch (operator){
  case '+':
    hasil = tambah(angka1, angka2);
    break;
  case '-':
    hasil = kurang(angka1, angka2);
    break;
  case '*':
    hasil = kali(angka1, angka2);
    break;
  case '/':
    hasil = bagi(angka1, angka2);
    break;
  case '^':
    hasil = pangkat(angka1, angka2);
    break;
  default:
    printf("Operator salah\n");
  }
  printf("Hasil: %.2lf", hasil);
  return 1;
}