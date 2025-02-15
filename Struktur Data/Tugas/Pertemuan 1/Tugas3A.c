#include <stdio.h>

void judul();
void bacaData(int arr[], int pos, int size);

// Fungsi untuk membaca elemen array pada indeks tertentu
void bacaData(int arr[], int pos, int size) {
    if (pos >= 0 && pos < size) { // Memeriksa apakah indeks valid
        printf("Data pada posisi %d adalah: %d\n", pos, arr[pos]);
    } else {
        printf("Posisi tidak valid!\n"); // Pesan kesalahan jika indeks di luar jangkauan
    }
}

void judul(){
	printf("====================================\n");
    printf("Nama   	      : Muhammad Faiz Silmi\n");
    printf("NIM           : 24343099\n");
    printf("Matakuliah	: Struktur Data\n");
    printf("Nama Program  : Baca Data\n");
    printf("====================================\n\n\n");
}

int main() {
	judul();
    int arr[] = {10, 20, 30, 40, 50}; // Deklarasi array
    int size = sizeof(arr) / sizeof(arr[0]); // Menghitung ukuran array

    printf("Masukkan posisi data yang ingin dibaca (0-%d): ", size - 1);
    int pos;
    scanf("%d", &pos); // Meminta input indeks dari pengguna

    bacaData(arr, pos, size); // Memanggil fungsi untuk membaca data

    return 0;
}

