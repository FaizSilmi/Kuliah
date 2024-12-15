/* 	Nama File		  : tugas1.c
	Programmer	   	: Muhammad Faiz Silmi 24343099
	Tgl. pembuatan	: 09/11/2024
	Deskripsi		    : Menukar Elemen Array Menggunakan Pointer
*/
#include <stdio.h>
#include <stdlib.h>

void biodata(){
    printf("Menukar Elemen Array Menggunakan Pointer\n");
    printf("==========================================================\n");
    printf("Nama : Muhammad Faiz Silmi\n");
    printf("Nim  : 24343099\n");
    printf("==============================\n");
}
// Fungsi untuk mengalokasikan memori untuk array dinamis
int* alokasiArray(int ukuran) {
    int *array = (int*)malloc(ukuran * sizeof(int)); // Alokasi memori
    if (array == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        exit(1); // Keluar program jika alokasi gagal
    }
    return array;
}

// Fungsi untuk menginisialisasi array dengan nilai
void inisialisasiArray(int *array, int ukuran) {
    for (int i = 0; i < ukuran; i++) {
        array[i] = i + 1; // Mengisi array dengan nilai (1, 2, 3, ...)
    }
}

// Fungsi untuk membebaskan memori dari array dinamis
void bebasMemori(int *array) {
    free(array); // Membebaskan memori
}

int main() {
    biodata();
    int ukuran;

    // Meminta ukuran array dari pengguna
    printf("Masukkan ukuran array: ");
    scanf("%d", &ukuran);

    // Mengalokasikan memori untuk array dinamis
    int *array = alokasiArray(ukuran);

    // Menginisialisasi array dengan nilai
    inisialisasiArray(array, ukuran);

    // Menampilkan isi array
    printf("Isi array:\n");
    for (int i = 0; i < ukuran; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Membebaskan memori yang dialokasikan
    bebasMemori(array);

    return 0;
}
