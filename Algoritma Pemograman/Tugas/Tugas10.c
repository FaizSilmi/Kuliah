/*  
	Nama File      : Tugas10.c 
	Programmer     : Muhammad Faiz Silmi (24343099)
	Tgl. pembuatan : 06 September 2024 
	Deskripsi      : program ini untuk konversi waktu
*/

#include<stdio.h>

int main(){
	printf("Project Tugas 10 \n");
	printf("===================== \n");
	printf("Progammer : Muhammad Faiz Silmi \n");
	printf("NIM       : 24343099 \n");
	printf("===================== \n");
	// Masukkan variabel
	float jj, mm, dd, totaldd;
	printf("Masukkan Jam= ");
	scanf("%f", &jj);
	printf("Masukkan Menit= ");
	scanf("%f", &mm);
	printf("Masukkan Detik= ");
	scanf("%f", &dd);
	printf("%.0f : %.0f : %.0f \n", jj, mm, dd);
	// Konversi ke detik
	totaldd = jj * 3600 + mm * 60 + dd;
	// Hasil
	printf("Total Detik= %.0f \n", totaldd);
	printf("====================");
	printf(" ");
	// Masukkan variabel (detik ke format jj:mm:dd
	float jj2, mm2, dd2;
	int totaldd2;
	printf("Masukkan total detik yang mau di konversi= ");
	scanf("%d", &totaldd2);
	// Konversi
	jj2 = totaldd2 / 3600;
	mm2 = (totaldd2 % 3600)/ 60;
	dd2 = totaldd2 % 60;
	// Hasil
	printf("%.0f : %.0f : %.0f \n", jj2, mm2, dd2);
}
