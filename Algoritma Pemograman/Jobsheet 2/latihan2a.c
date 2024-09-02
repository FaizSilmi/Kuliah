/*  Nama File   : latihan2a.c 
 Programmer     : Muhammad Faiz Silmi (24343099)
 Tgl. pembuatan : 02 September 2024 
 Deskripsi      : program ini melakukan perhitungan luas dan keliling persegi panjang 
*/

#include<stdio.h>

int main() 
{ 
	printf("Project jobsheet 2 A \n");
	printf("===================== \n");
	printf("Progammer : Muhammad Faiz Silmi A \n");
	printf("NIM       : 24343099 \n");
	printf("===================== \n");
	printf("  \n");
	float panjang, lebar, luas, kel; 
	// Pemasukan Nilai
	printf("Panjang = "); 
	scanf("%f", &panjang); 
	printf("Lebar = "); 
	scanf("%f", &lebar); 
	// Proses Penghitungan 
	luas = panjang * lebar; 
	kel = 2 * panjang + 2 * lebar; 
	// Menampilkan hasil 
	printf("Luas = %.2f \n", luas); 
	printf("Keliling = %.2f \n", kel); 
	return 0;
} 

