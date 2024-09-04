/*  
	Nama File      : Tugas3.c 
	Programmer     : Muhammad Faiz Silmi (24343099)
	Tgl. pembuatan : 04 September 2024 
	Deskripsi      : program ini menentukan nilai luas kulit/selimut benda
*/

#include<stdio.h>
#include<math.h>
#define PHI 3.14

int main(){
	printf("Project Tugas no. 3 \n");
	printf("===================== \n");
	printf("Progammer : Muhammad Faiz Silmi A \n");
	printf("NIM       : 24343099 \n");
	printf("===================== \n");
	float sisikubus, selimutkubus, panjangbalok, lebarbalok, tinggibalok, selimutbalok, diameter, tinggitabung, selimuttabung;
	// Masukkan variabel kubus
	printf("Masukkan sisi kubus= ");
	scanf("%f", &sisikubus);
	// Menghitung luas selimut kubus
	selimutkubus = 6 * (sisikubus * sisikubus);
	//Hasil selimut kubus
	printf("Luas selimut kubus: %.2f \n", selimutkubus);
	printf("========================= \n");
	
	// Masukkan variabel balok
	printf("Masukkan panjang balok: ");
	scanf("%f", &panjangbalok);
	printf("Masukkan lebar balok: ");
	scanf("%f", &lebarbalok);
	printf("Masukkan tinggi balok: ");
	scanf("%f", &tinggibalok);
	// Menghitung luas selimut balok
	selimutbalok = 2.00 * ((panjangbalok * lebarbalok) + (panjangbalok * tinggibalok) + (lebarbalok * tinggibalok));
	// Hasil selimut balok
	printf("Luas selimut balok: %.2f \n", selimutbalok);
	printf("========================= \n");
	
	// Masukkan variabel tabung
	printf("Masukkan diameter: ");
	scanf("%f", &diameter);
	printf("Masukkan tinggi tabung: ");
	scanf("%f", &tinggitabung);
	// Menghitung luas selimut tabung
	selimuttabung = 2.00 * PHI * (diameter / 2.00) * tinggitabung;
	// Hasil selimut tabung
	printf("Luas selimut tabung: %.2f \n", selimuttabung);
	printf("========================= \n");
}
