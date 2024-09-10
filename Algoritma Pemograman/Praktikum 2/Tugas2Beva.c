#include<stdio.h>
#define BUNGA 10

int main(){
	float hargapokok, dp, waktucicilan, biayacicilan, angsuran, bunga;
	// Masukkan variabel
	printf("Masukkan Harga Pokok= ");
	scanf("%f", &hargapokok);
	printf("Masukkan DP= ");
	scanf("%f", &dp);
	printf("Masukkan berapa lama cicilan= ");
	scanf("%f", &waktucicilan);
	// Penghitungan
	biayacicilan = 	hargapokok / waktucicilan;
	bunga = (hargapokok * (BUNGA/100)) / waktucicilan;
	angsuran = biayacicilan + bunga;
	// Menampilkan hasil
	printf("Cicilan perbulan= %.2f", angsuran);
}

