/* 	Nama File		  : tugas1.c
	Programmer	   	: Muhammad Faiz Silmi 24343099
	Tgl. pembuatan	: 09/11/2024
	Deskripsi		    : Menukar Elemen Array Menggunakan Pointer
*/
#include <stdio.h>
#include <string.h>

#define MAX_BUKU 3
#define MAX_STRING 50

void biodata(){
    printf("Menukar Elemen Array Menggunakan Pointer\n");
    printf("==========================================================\n");
    printf("Nama : Muhammad Faiz Silmi\n");
    printf("Nim  : 24343099\n");
    printf("==============================\n");
}
// Definisi struct Buku
struct Buku {
    char judul[MAX_STRING];
    char pengarang[MAX_STRING];
    int tahun_terbit;
};

// Fungsi untuk menampilkan informasi buku
void tampilkanBuku(struct Buku *buku, int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        printf("Buku %d:\n", i + 1);
        printf("Judul: %s\n", (buku + i)->judul);
        printf("Pengarang: %s\n", (buku + i)->pengarang);
        printf("Tahun Terbit: %d\n\n", (buku + i)->tahun_terbit);
    }
}

// Fungsi untuk mengisi data buku
void isiDataBuku(struct Buku *buku, int index, const char *judul, const char *pengarang, int tahun_terbit) {
    strcpy((buku + index)->judul, judul);
    strcpy((buku + index)->pengarang, pengarang);
    (buku + index)->tahun_terbit = tahun_terbit;
}

int main() {
    biodata();
    struct Buku koleksi[MAX_BUKU];

    // Mengisi data buku menggunakan pointer
    isiDataBuku(koleksi, 0, "Pemrograman C", "Budi Santoso", 2020);
    isiDataBuku(koleksi, 1, "Algoritma dan Struktur Data", "Andi Setiawan", 2019);
    isiDataBuku(koleksi, 2, "Basis Data", "Cahyo Widodo", 2021);

    // Menampilkan informasi buku menggunakan pointer
    printf("Informasi Koleksi Buku:\n");
    tampilkanBuku(koleksi, MAX_BUKU);

    return 0;
}
