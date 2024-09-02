/*  Nama File      : latihan2a.c 
	Programmer     : Muhammad Faiz Silmi (24343099)
	Tgl. pembuatan : 02 September 2024 
	Deskripsi      : program ini melakukan perhitungan sisi miring segitiga siku-siku
*/

#include <stdio.h>
#include <conio.h> 
#include <math.h>

int main() {
	printf("Project jobsheet 2 B \n");
	printf("===================== \n");
	printf("Progammer : Muhammad Faiz Silmi A \n");
	printf("NIM       : 24343099 \n");
	printf("===================== \n");
	float x,y,r;
	// Masukkan nilai
	printf("Sisi X = ");
	scanf("%f",&x);
	printf("Sisi Y = ");  
	scanf("%f",&y);
	r = sqrt(x*x + y*y); 
	printf("Sisi Miring =%.2f \n",r); 
	return 0;
} 
