/*  Nama File       : latihan7a.c
    Programmer      : Muhammad Faiz Silmi 24343099
    Tgl. pembuatan  : 19/10/2024
    Deskripsi       : Pointer dan Array
*/

#include <stdio.h>

// Deklarasi fungsi untuk menampilkan elemen-elemen array menggunakan pointer
void tampilkanArray(int *ptr, int size);

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;
    printf(" Pointer dan Array \n");
    printf("=============================\n");
    printf("Nama : Muhammad Faiz Silmi\n");
    printf("Nim  : 24343099\n");
    printf("=============================\n");
    // Menampilkan elemen-elemen array menggunakan pointer
    tampilkanArray(ptr, 5);
    //printf(“Alamat pertama dari element pertama arr (arr): %p\n”, ptr);
    return 0;
}

// Definisi fungsi untuk menampilkan elemen-elemen array menggunakan pointer
void tampilkanArray(int *ptr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Elemen ke-%d: %d\n", i, *(ptr + i));
    }
}
