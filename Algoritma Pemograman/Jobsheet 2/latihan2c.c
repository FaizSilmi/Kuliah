/*  
	Nama File      : latihan2c.c 
	Programmer     : Muhammad Faiz Silmi (24343099)
	Tgl. pembuatan : 02 September 2024 
	Deskripsi      : program ini melakukan perhitungan luas dan keliling lingkaran
*/

#include <stdio.h> 
#define PHI 3.14

int main() {
	printf("Project Jobsheet 2 C \n");
	printf("==================== \n");
	printf("Nama  : Muhammad Faiz Silmi \n");
	printf("NIM   : 24343099 \n");
	printf("==================== \n");
	printf("   \n");
	float radius, luas, kel;
	// Memasukkan nilai jari-jari dari pengguna 
	printf("Masukkan nilai jari-jari lingkaran: ");
	scanf("%f",&radius);
	// Menghitung Luas dan keliling)
	luas = PHI * radius * radius; 
	kel = 2 * PHI * radius;
	// Menunjukkan Hasi
	printf("Luas=  %.2f \n", luas);
	printf("Keliling= %.2f \n", kel);
	return 0;
}


