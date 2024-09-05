/*  
	Nama File      : Tugas6.c 
	Programmer     : Muhammad Faiz Silmi (24343099)
	Tgl. pembuatan : 05 September 2024 
	Deskripsi      : program ini menghitung volume kubus, kotak, tabung, dan bola
*/

#include<stdio.h>
#define PHI 3.14

int main(){
	printf("Project Tugas no. 6 \n");
	printf("===================== \n");
	printf("Progammer : Muhammad Faiz Silmi \n");
	printf("NIM       : 24343099 \n");
	printf("===================== \n");
	printf(" \n");
	float sisikubus, vkubus;
	float panjangkotak, lebarkotak, tinggikotak, vkotak;
	float r, tinggitabung, vtabung;
	float rbola, vbola, lbola;
	// Masukkan variabel kubus
	printf("Menghitung volume kubus \n");
	printf("======================= \n");
	printf("Masukkan sisi kubus= ");
	scanf("%f", &sisikubus);
	// Menghitung volume kubus
	vkubus = sisikubus * sisikubus * sisikubus;
	// Hasil volume kubus
	printf("Hasil volume kubus: %.2f \n", vkubus);
	printf("========================== \n");
	printf(" \n");
	
	// Masukkan variabel kotak
	printf("Menghitung volume kotak \n");
	printf("======================= \n");
	printf("Masukkan panjang kotak=");
	scanf("%f", &panjangkotak);
	printf("Masukkan lebar kotak= ");
	scanf("%f", &lebarkotak);
	printf("Masukkan tinggi kotak= ");
	scanf("%f", &tinggikotak);
	// Menghitung volume kotak
	vkotak = panjangkotak * lebarkotak * tinggikotak;
	// Hasil volume kotak
	printf("Hasil volume tabung: %.2f \n", vkotak);
	printf("========================== \n");
	printf(" \n");
	
	// Masukkan variabel tabung
	printf("Menghitung volume tabung \n");
	printf("======================= \n");
	printf("Masukkan jari jari= ");
	scanf("%f", &r);
	printf("Masukkan tinggi tabung");
	scanf("%f", &tinggitabung);
	// Menghitung volume tabung
	vtabung = PHI * (r*r) *tinggitabung;
	// Hasil volume tabung
	printf("Hasil volume tabung: %.2f \n", vtabung);
	printf("========================== \n");
	printf(" \n");

	// Masukkan variabel bola
	printf("Menghitung volume dan luas bola \n");
	printf("======================= \n");
	printf("Masukkan jari jari: ");
	scanf("%", rbola);
	// Menghitung luas bola
	lbola = 4.00 * PHI * (r*r);
	// Menghitung volume bola
	vbola = (4.00 / 3.00) * PHI * (r * r * r);
	// Menampilkan hasil luas dan keliling bola
	printf("Hasil luas bole: %.2f \n", lbola);
	printf("Hasil volume bola: %.2f \n", vbola);
	printf("========================== \n");
}
