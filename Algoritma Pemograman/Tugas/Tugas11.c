/*  
	Nama File      : Tugas11.c 
	Programmer     : Muhammad Faiz Silmi (24343099)
	Tgl. pembuatan : 06 September 2024 
	Deskripsi      : program ini untuk konversi waktu
*/

#include<stdio.h>

int main (){
	printf("Project Tugas 11 \n");
	printf("===================== \n");
	printf("Progammer : Muhammad Faiz Silmi \n");
	printf("NIM       : 24343099 \n");
	printf("===================== \n");
	float cm, m, km;
	// Masukkan variabel 	
	printf("Masukkan nilai cm= ");
	scanf("%f", &cm);
	// Konversi
	m = cm * 100;
	km = cm * 100000;
	// Hasil
	printf("Meter= %.2f \nKilo Meter= %.2f \n", m, km);
	printf("============================ \n");
	printf("  \n");
	
	float cm2, m2, km2;
	// Masukkan variabel 	
	printf("Masukkan nilai KM= ");
	scanf("%f", &km2);
	// Konversi
	m2 = km2 / 100;
	cm2 = km2 / 100000;
	// Hasil
	printf("Meter= %.5f \nCentiMeter= %.5", m2, cm2);
}
