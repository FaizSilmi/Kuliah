/*  
	Nama File      : TUGAS2B.c 
	Programmer     : Muhammad Faiz Silmi (24343099)
	Tgl. pembuatan : 02 September 2024 
	Deskripsi      : program ini menghitung tinggi layangan
*/

#include<stdio.h>
#include<math.h>
#define PHI 3.14

int main(){
	printf("Project Tugas 2 B Evaluasi \n");
	printf("===================== \n");
	printf("Progammer : Muhammad Faiz Silmi A \n");
	printf("NIM       : 24343099 \n");
	printf("===================== \n");
	float a, panjangtali, sudut, sudutradian;
	// Masukkan variabel yang dibutuhkan
	printf("Masukkan panjang tali= ");
	scanf("%f", &panjangtali);
	printf("Masukkan sudut elevasi= ");
	scanf("%f", &sudut);
	// Konversi sudut derajat ke radian
	sudutradian = sudut * PHI / 180.00;
	// Menghitung sisi tegak
	a = panjangtali * sin(sudutradian);
	// Hasil
	printf("Tinggi layangan= %.2f Meter \n", a);
}
