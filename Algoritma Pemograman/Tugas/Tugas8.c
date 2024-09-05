/*  
	Nama File      : Tugas7.c 
	Programmer     : Muhammad Faiz Silmi (24343099)
	Tgl. pembuatan : 05 September 2024 
	Deskripsi      : program ini menghitung kebutuhan kalori manusia
*/

#include<stdio.h>

int main(){
	printf("Project Tugas 8 \n");
	printf("===================== \n");
	printf("Progammer : Muhammad Faiz Silmi \n");
	printf("NIM       : 24343099 \n");
	printf("===================== \n");
	char konfirmasi;
	float x1, y1, x2, y2, titikp, titikq, titiktengahp, titiktengahq;
	printf("Masukkan koordinat X1= ");
	scanf("%f", &x1);
	printf("Masukkan koordinat Y1= ");
	scanf("%f", &y1);
	printf("Masukkan koordinat X2= ");
	scanf("%f", &x2);
	printf("Masukkan koordinat Y2= ");
	scanf("%f", &y2);
	// Konfirmasi data titik p dan q
	printf("titik p (%.0f, %.0f)", x1, y1);
	printf("titik q (%.0f, %.0f) \n", x2, y2);
	printf("Apakah koordinat sudah benar? (Y/N)");
	scanf(" %c", &konfirmasi);
	if (konfirmasi == 'Y' || konfirmasi == 'y'){
		titiktengahp = (x1+y1)/2.00;
		titiktengahq = (x2+y2)/2.00;
		printf("Titik tengah= %.0f, %.0f", titiktengahp, titiktengahq);
	}
	else {
		printf("Silahkan restart program \n");
	}
}
