/*  Nama File       : latihan7a.c
    Programmer      : Muhammad Faiz Silmi 24343099
    Tgl. pembuatan  : 19/10/2024
    Deskripsi       : Deklarasi dan Penggunaan Pointer
*/

#include <stdio.h>

// Deklarasi fungsi untuk menampilkan nilai variabel melalui pointer
void tampilkanNilai(int *ptr);

int main() {
    int nilai = 10;
    int *ptr = &nilai;
    
    printf(" Deklarasi dan Penggunaan Pointer \n");
    printf("=============================\n");
    printf("Nama : Muhammad Faiz Silmi\n");
    printf("Nim  : 24343099\n");
    printf("=============================\n");
    // Menampilkan nilai variabel melalui pointer
    tampilkanNilai(ptr);

    return 0;
}

// Definisi fungsi untuk menampilkan nilai variabel melalui pointer
void tampilkanNilai(int *ptr) {
    printf("Nilai variabel: %d\n", *ptr);
}
