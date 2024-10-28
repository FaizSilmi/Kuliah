#include <stdio.h>

// Deklarasi fungsi untuk menampilkan elemen-elemen array menggunakan pointer
void tampilkanArray(int *ptr, int size);

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;

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
