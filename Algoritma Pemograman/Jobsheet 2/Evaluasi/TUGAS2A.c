/*  
	Nama File      : TUGAS2Ac.c 
	Programmer     : Muhammad Faiz Silmi (24343099)
	Tgl. pembuatan : 02 September 2024 
	Deskripsi      : program ini menghitung tahanan, arus, dan tegangan rangkaian paralel
*/


#include<stdio.h>

int main(){
	printf("Project Tugas 2 A Evaluasi \n");
	printf("===================== \n");
	printf("Progammer : Muhammad Faiz Silmi A \n");
	printf("NIM       : 24343099 \n");
	printf("===================== \n");
	float r1, r2, rt, v, i, vr1, vr2;
	// Masukkan variabel
	printf("Masukkan R1= ");
	scanf("%f", &r1);
	printf("Masukkan R2= ");
	scanf("%f", &r2);
	printf("Masukkan VR1= ");
	scanf("%f", &vr1);
	printf("Masukkan VR2= ");
	scanf("%f", &vr2);
	// Proses menghitung
	rt = (r1 * r2) / (r1 + r2);
	v = vr1 + vr2;
	i = v / rt;
	// Hasil
	printf("Total tahanan= %.2f Ohm \n", rt);
	printf("Total tegangan= %.2f Volt \n", v);
	printf("Total arus= %.2f Ampere \n", i);
	return 0;
}
