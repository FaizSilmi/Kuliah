/* 	Nama File		: Eva5.c
	Programmer		: Muhammad Faiz Silmi
	Tgl. pembuatan	: 07/10/2024
	Deskripsi		: Program manajemen tugas
*/

#include <stdio.h>
#include <stdlib.h>

// Menampilkan judul program
void judul() {
    printf("===== Aplikasi Kasir Sederhana =====\n");
}

// Fungsi untuk mengumpulkan data
void inputData(int *jumlahBarang, int *hargaBarang) {
    printf("Jumlah Barang: ");
    scanf("%d", jumlahBarang);
    printf("Harga per Barang: ");
    scanf("%d", hargaBarang);
}

// Fungsi untuk menghitung total awal
double totalAwal(int jumlahBarang, int hargaBarang) {
    return jumlahBarang * hargaBarang;
}

// Fungsi utama
int main() {
    int jumlahBarang = 0, hargaBarang = 0;
    double total, diskon, totalakhir;

    judul();
    
    inputData(&jumlahBarang, &hargaBarang);
    
    total = totalAwal(jumlahBarang, hargaBarang);
    diskon = ((total * 10)/100);
    totalakhir = total - diskon;
    
    printf("====================================\n");
    printf("Jumlah Barang: %.2d\n", jumlahBarang);
    printf("Harga per barang: %.2d\n", hargaBarang);
    printf("Total belanja awal: %.2lf\n", total);
    printf("Diskon yang diperoleh: %.2lf\n", diskon);
	printf("Total belanja setelah diskon: %.2lf\n", totalakhir);
	
    return 0;
}

