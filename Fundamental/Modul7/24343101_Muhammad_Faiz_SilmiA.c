/* 	Nama File		: array1.c
	Programmer		: Muhammad Faiz Silmi
	Tgl. pembuatan	: 19/10/2024
	Deskripsi		: Menampilkan Elemen Array
*/
#include <stdio.h>
void biodata();
int main() {
    biodata();
    // Deklarasi dan inisialisasi array bertipe int dengan ukuran 5
    int angka[5] = {10, 20, 30, 40, 50};

    // Menampilkan semua elemen array menggunakan loop
    printf("Elemen-elemen dalam array angka:\n");
    for (int i = 0; i < 5; i++) {
        printf("angka[%d] = %d\n", i, angka[i]);
    }

    return 0;
}

void biodata(){
    printf(" Menampilkan Elemen Array\n");
    printf("==========================================================\n");
    printf("Nama : Muhammad Faiz Silmi\n");
    printf("Nim  : 24343099\n");
    printf("==============================\n");
}