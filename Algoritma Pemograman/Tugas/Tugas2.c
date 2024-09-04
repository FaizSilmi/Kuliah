/*  
	Nama File      : Tugas2.c 
	Programmer     : Muhammad Faiz Silmi (24343099)
	Tgl. pembuatan : 04 September 2024 
	Deskripsi      : program ini menentukan keliling bentuk bentuk geometris 
*/

#include<stdio.h>
#define PHI 3.14
#include<math.h>

int main(){
	printf("Project Tugas no. 1 \n");
	printf("===================== \n");
	printf("Progammer : Muhammad Faiz Silmi A \n");
	printf("NIM       : 24343099 \n");
	printf("===================== \n");
	float alas, tinggi, pjgmiring, kelilingT, panjang, lebar, kelilingP, diameter, kelilingL;
	// Masukkan variabel (segitiga)
	printf("Masukkan panjang alas segitiga: ");
	scanf("%f", &alas);
	printf("Masukkan panjang tinggi segitiga: ");
	scanf("%f", &tinggi);
	// Menghitung panjang sisi miring
	pjgmiring = sqrt (alas*alas + tinggi * tinggi);
	// Menghitung keliling segitiga
	kelilingT = alas + tinggi + pjgmiring;
	// Hasil
	printf("Sisi miring= %.2f \n", pjgmiring);
	printf("Keliling= %.2f \n", kelilingT);
	printf("============================= \n");
	
	// Masukkan variabel (persegi panjang)
	printf("Masukkan panjang persegi panjang: ");
	scanf("%f", &panjang);
	printf("Masukkan lebar persegi panjang: ");
	scanf("%f", &lebar);
	// Menghitung keliling persegi panjang
	kelilingP = 2.00 * (panjang + lebar);
	// Hasil
	printf("Keliling= %.2f \n", kelilingP);
	printf("============================= \n");
	
	// Masukkan variabel (lingkaran)
	printf("Masukkan diameter lingkaran: ");
	scanf("%f", &diameter);
	// Menghitung keliling lingkaran
	kelilingL = PHI * diameter;
	// Hasil
	printf("Keliling= %.2f \n", kelilingL);
	printf("============================= \n");
}
