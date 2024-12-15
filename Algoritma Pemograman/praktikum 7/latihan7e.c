/*  Nama File       : latihan7a.c
    Programmer      : Muhammad Faiz Silmi 24343099
    Tgl. pembuatan  : 19/10/2024
    Deskripsi       : Mengakses Array Dinamis Menggunakan Pointer
*/

#include <stdio.h>
#include <stdlib.h>

// Deklarasi fungsi untuk menampilkan elemen-elemen array dinamis
void tampilkanArray(int *arr, int size);

int main() {
    int size = 5;
    int *arr = (int*)malloc(size * sizeof(int));
    printf(" Mengakses Array Dinemis Menggunakan Pointer \n");
    printf("=============================\n");
    printf("Nama : Muhammad Faiz Silmi\n");
    printf("Nim  : 24343099\n");
    printf("=============================\n");
    // Memeriksa apakah memori berhasil dialokasikan
    if (arr == NULL) {
        printf("Memori tidak berhasil dialokasikan.\n");
        return 1;
    }

    // Inisialisasi elemen-elemen array
    for (int i = 0; i < size; i++) {
        arr[i] = i * 10;
    }

    // Menampilkan elemen-elemen array
    tampilkanArray(arr, size);

    // Membebaskan memori yang dialokasikan
    free(arr);

    return 0;
}

// Definisi fungsi untuk menampilkan elemen-elemen array dinamis
void tampilkanArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Elemen ke-%d: %d\n", i, arr[i]);
    }
}
