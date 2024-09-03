/*  
	Nama File      : TUGAS2B.c 
	Programmer     : Muhammad Faiz Silmi (24343099)
	Tgl. pembuatan : 02 September 2024 
	Deskripsi      : program ini menghitung tinggi layangan
*/

#include<stdio.h>
#include<math.h>

int main(){
	printf("Project Tugas 2 B Evaluasi \n");
	printf("===================== \n");
	printf("Progammer : Muhammad Faiz Silmi A \n");
	printf("NIM       : 24343099 \n");
	printf("===================== \n");
	float a, b, c;
	// Masukkan variabel yang dibutuhkan
	printf("Masukkan panjang tali= ");
	scanf("%f", &c);
	printf("Masukkan jarak mendatar= ");
	scanf("%f", &b);
	// Menghitung sisi tegak
	a = sqrt(c*c - b*b);
	// Hasil
	printf("Tinggi layangan= %.2f \n", a);
}

