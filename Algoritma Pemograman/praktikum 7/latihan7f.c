/*  Nama File       : latihan7a.c
    Programmer      : Muhammad Faiz Silmi 24343099
    Tgl. pembuatan  : 19/10/2024
    Deskripsi       : Mengakses Array Dinamis Menggunakan Pointer
*/

#include <stdio.h>

// Definisi struktur data
struct Mahasiswa {
    char nama[50];
    int umur;
    float ipk;
};

// Deklarasi fungsi untuk menampilkan informasi dari struktur menggunakan pointer
void tampilkanMahasiswa(struct Mahasiswa *mhs);

int main() {
    struct Mahasiswa mhs;
    struct Mahasiswa *ptr = &mhs;
    printf(" Mengakses Array Dinemis Menggunakan Pointer \n");
    printf("=============================\n");
    printf("Nama : Muhammad Faiz Silmi\n");
    printf("Nim  : 24343099\n");
    printf("=============================\n");
    // Inisialisasi elemen-elemen struktur melalui pointer
    strcpy(ptr->nama, "Budi");
    ptr->umur = 20;
    ptr->ipk = 3.75;

    // Menampilkan informasi dari struktur menggunakan pointer
    tampilkanMahasiswa(ptr);

    return 0;
}

// Definisi fungsi untuk menampilkan informasi dari struktur menggunakan pointer
void tampilkanMahasiswa(struct Mahasiswa *mhs) {
    printf("Nama: %s\n", mhs->nama);
    printf("Umur: %d\n", mhs->umur);
    printf("IPK: %.2f\n", mhs->ipk);
}
