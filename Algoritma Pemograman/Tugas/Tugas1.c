/*  
	Nama File      : Tugas1.c 
	Programmer     : Muhammad Faiz Silmi (24343099)
	Tgl. pembuatan : 02 September 2024 
	Deskripsi      : program ini menghitung total belanja setelah kena pajak
*/

#include<stdio.h>
#define PAJAK  0.15

int main(){
	printf("Project Tugas no. 1 \n");
	printf("===================== \n");
	printf("Progammer : Muhammad Faiz Silmi A \n");
	printf("NIM       : 24343099 \n");
	printf("===================== \n");
	float nilai1, nilai2, nilai3, biaya, total;
	// Masukkan nilai belanjaan
	printf("Masukkan nilai belanjaan 1= ");
	scanf("%f", &nilai1);
	printf("Masukkan nilai belanjaan 2= ");
	scanf("%f", &nilai2);
	printf("Masukkan nilai belanjaan 2= ");
	scanf("%f", &nilai3);
	//Menjumlahkan total belanja
	biaya = nilai1 + nilai2 +nilai3;
	//Total belanja setelah kena pajak
	total = biaya + (biaya * PAJAK);
	// Menampilkan total belanja setelah kena pajak
	printf("Total biaya= %.2f \n", total);
	return 0;
}
