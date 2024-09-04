/*  
	Nama File      : Tugas5.c 
	Programmer     : Muhammad Faiz Silmi (24343099)
	Tgl. pembuatan : 04 September 2024 
	Deskripsi      : program ini menghitung luas lingkaran, persegi, dan segitiga sama kaki
*/

#include<stdio.h>
#define PHI 3.14

int main (){
	printf("Project Tugas no. 5 \n");
	printf("===================== \n");
	printf("Progammer : Muhammad Faiz Silmi \n");
	printf("NIM       : 24343099 \n");
	printf("===================== \n");
	float sisipersegi, luaspersegi;
	float luassegitiga, alas, tinggi;
	float luaslingkaran, radius;
	// Masukkan variabel persegi
	printf("Masukkan sisi persegi= ");
	scanf("%f", &sisipersegi);
	// Menghitung luas persegi
	luaspersegi = sisipersegi * sisipersegi;
	// Hasil
	printf("Hasil luas persegi= %.2f\n", luaspersegi);
	printf("====================== \n");
	
	// Masukkan variabel segi tiga
	printf("Masukkan tinggi segi tiga sama kaki= ");
	scanf("%f", &tinggi);
	printf("Masukkan alas segi tiga sama kaki= ");
	scanf("%f", &alas);
	// Menghitung luas segi tiga
	luassegitiga = (alas * tinggi) / 2.00;
	// Hasil
	printf("Hasil luas segi tiga sama kaki= %.2f\n", luassegitiga);
	printf("========================= \n");
	
	// Masukkan variable lingkaran
	printf("Masukkan radius lingkaran= ");
	scanf("%f", &radius);
	// Menghitung luas lingkaran
	luaslingkaran = PHI * (radius * radius);
	// Hasil
	printf("Hasil luas lingkaran= %.2f\n", luaslingkaran);
	printf("========================= \n");
}
