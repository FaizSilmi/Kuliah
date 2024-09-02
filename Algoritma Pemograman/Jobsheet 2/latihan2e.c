/*  
	Nama File      : latihan2c.c 
	Programmer     : Muhammad Faiz Silmi (24343099)
	Tgl. pembuatan : 02 September 2024 
	Deskripsi      : program ini menghitung harga lembar foto kopi
*/

#include<stdio.h>
#define HARGA  500.00
int main(){
	printf("Project jobsheet 2 E \n");
	printf("===================== \n");
	printf("Progammer : Muhammad Faiz Silmi A \n");
	printf("NIM       : 24343099 \n");
	printf("===================== \n");
	float lembar, biaya;
	// Masukkan jumlah lembar
	printf("Masukkan jumlah lembar= ");
	scanf("%f", &lembar);
	//Proses
	biaya = lembar * HARGA;
	//Hasil
	printf("Total biaya= %.2f \n", biaya);
	return 0;
}
