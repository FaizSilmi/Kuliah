/*  
	Nama File      : Tugas14.c 
	Programmer     : Muhammad Faiz Silmi (24343099)
	Tgl. pembuatan : 07 September 2024 
	Deskripsi      : program ini untuk mencari ketinggian tanah di dalam suatu bidang datar
*/

#include<stdio.h>
#include<math.h>
#define PHI 3.14

int main(){
	float d, k, t, p, l;
	printf("Project Tugas 14 \n");
	printf("===================== \n");
	printf("Progammer : Muhammad Faiz Silmi \n");
	printf("NIM       : 24343099 \n");
	printf("===================== \n");
	// Masukkan variabel
	printf("Masukkan kedalaman= ");
	scanf("%f", &k);
	printf("Masukkan diameter= ");
	scanf("%f", &d);
	printf("Masukkan lebar= ");
	scanf("%f", &l);
	printf("Masukkan panjang= ");
	scanf("%f", &p);
	// Proses
	t = (PHI * ((d/2) * (d/2)) * k)/(l*p);
	// Hasil
	printf("Ketinggian tanah= %.2f", t);
}
