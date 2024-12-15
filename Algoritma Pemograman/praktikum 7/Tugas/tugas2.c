/* 	Nama File		  : tugas1.c
	Programmer	   	: Muhammad Faiz Silmi 24343099
	Tgl. pembuatan	: 09/11/2024
	Deskripsi		    : Menukar Elemen Array Menggunakan Pointer
*/
#include <stdio.h>

void biodata(){
    printf("Menukar Elemen Array Menggunakan Pointer\n");
    printf("==========================================================\n");
    printf("Nama : Muhammad Faiz Silmi\n");
    printf("Nim  : 24343099\n");
    printf("==============================\n");
}
// Fungsi untuk menukar dua elemen menggunakan pointer
void tukarElemen(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk menukar elemen-elemen dalam array
void tukarArray(int *array, int ukuran) {
    // Menukar elemen dari ujung awal ke ujung akhir
    for (int i = 0; i < ukuran / 2; i++) {
        // Menggunakan pointer aritmatika untuk menukar elemen array
        tukarElemen(&array[i], &array[ukuran - 1 - i]);
    }
}

int main() {
    biodata();
    int array[] = {1, 2, 3, 4, 5};  // Array dengan elemen yang ingin ditukar
    int ukuran = sizeof(array) / sizeof(array[0]);  // Mendapatkan ukuran array

    printf("Array sebelum ditukar:\n");
    for (int i = 0; i < ukuran; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Memanggil fungsi untuk menukar elemen dalam array
    tukarArray(array, ukuran);

    printf("Array setelah ditukar:\n");
    for (int i = 0; i < ukuran; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
