/* 	Nama File		: array3.c
	Programmer		: Muhammad Faiz Silmi
	Tgl. pembuatan	: 19/10/2024
	Deskripsi		: Mengganti Nilai Elemen Array
*/
#include <stdio.h>
void biodata();
int main() {
    biodata();
    int angka[5] = {10, 20, 30, 40, 50}; // Inisialisasi array dengan nilai awal
    int indeks, nilaiBaru;

    // Tampilkan array awal
    printf("Array awal:\n");
    for (int i = 0; i < 5; i++) {
        printf("angka[%d] = %d\n", i, angka[i]);
    }

    // Minta pengguna memasukkan indeks elemen yang ingin diganti dan nilai baru
    printf("\nMasukkan indeks elemen yang ingin diganti (0-4): ");
    scanf("%d", &indeks);

    // Validasi indeks
    if (indeks < 0 || indeks >= 5) {
        printf("Indeks tidak valid! Masukkan indeks antara 0 dan 4.\n");
        return 1;
    }

    printf("Masukkan nilai baru: ");
    scanf("%d", &nilaiBaru);

    // Ganti nilai elemen pada indeks yang dipilih
    angka[indeks] = nilaiBaru;

    // Tampilkan array setelah penggantian nilai
    printf("\nArray setelah nilai diganti:\n");
    for (int i = 0; i < 5; i++) {
        printf("angka[%d] = %d\n", i, angka[i]);
    }

    return 0;
}


void biodata(){
    printf(" Mengganti Nilai Elemen Array\n");
    printf("==========================================================\n");
    printf("Nama : Muhammad Faiz Silmi\n");
    printf("Nim  : 24343099\n");
    printf("==============================\n");
}
