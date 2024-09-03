/*  
	Nama File      : TUGAS2C.c 
	Programmer     : Muhammad Faiz Silmi (24343099)
	Tgl. pembuatan : 02 September 2024 
	Deskripsi      : program ini menghitung kebutuhan kalori manusia
*/

#include<stdio.h>


int main(){
	printf("Project Tugas 2 C Evaluasi \n");
	printf("===================== \n");
	printf("Progammer : Muhammad Faiz Silmi A \n");
	printf("NIM       : 24343099 \n");
	printf("===================== \n");
	int pekerjaan;
	char kelamin;
	float kalori, konsumsi, kalorip, umur, tb, bb;
	// Masukkan variabel
	printf("Masukkan jenis kelamin (L/P)= ");
	scanf(" %c", &kelamin);
	printf("Masukkan berat badan= ");
	scanf("%f", &bb);
	printf("Masukkan tinggi badan= ");
	scanf("%f", &tb);
	printf("Masukkan umur= ");
	scanf("%f", &umur);
	// proses
	if (kelamin == 'L' || kelamin == 'l'){
	konsumsi = (88.4 + 13.4 * bb) + (4.8 * tb)-(5.68 * umur);
	printf("%.2f \n", konsumsi);
	}
	else if (kelamin == 'P' || kelamin == 'p'){
	konsumsi = (447.6 + 9.25 * bb) + (3.1 * tb)-(4.33 * umur);
	printf("%.2f \n", konsumsi);
	}
	
	printf("Pilih tingkat pekerjaan: \n");
	printf("1. Sedikit bergerak \n");
	printf("2. Banyak bergerak \n");
	scanf("%d", &pekerjaan);
	
	switch(pekerjaan){
		case 1:
			kalori = konsumsi *1.2;
			break;
		case 2:
			kalori = konsumsi *1.5;
			break;
	}
	printf("Kebutuhan kalori= %.2f kalori \n", kalori);
}
