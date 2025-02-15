#include <stdio.h>

void judul();
void tambahData(int arr[], int *size, int capacity, int data, int pos);

// Fungsi untuk menambahkan elemen ke array
void tambahData(int arr[], int *size, int capacity, int data, int pos) {
	int i;
    if (*size >= capacity) { // Memeriksa apakah array penuh
        printf("Array penuh! Tidak dapat menambahkan data.\n");
        return;
    }
    for (i = *size; i > pos; i--) { // Geser elemen ke kanan
        arr[i] = arr[i - 1];
    }
    arr[pos] = data; // Tambahkan elemen baru
    (*size)++; // Perbarui ukuran array
}

void judul(){
	printf("====================================\n");
    printf("Nama   	      : Muhammad Faiz Silmi\n");
    printf("NIM           : 24343099\n");
    printf("Matakuliah    : Struktur Data\n");
    printf("Nama Program  : Tambah Data\n");
    printf("====================================\n\n\n");
}

int main() {
	judul();
	int i;
    int arr[10] = {10, 20, 30, 40, 50}; // Deklarasi array
    int size = 5; // Ukuran awal array
    int capacity = 10; // Kapasitas maksimum array

    printf("Sebelum penambahan:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nMenambahkan elemen 25 di posisi 2...\n");
    tambahData(arr, &size, capacity, 25, 2); // Menambahkan elemen baru

    printf("Setelah penambahan:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

