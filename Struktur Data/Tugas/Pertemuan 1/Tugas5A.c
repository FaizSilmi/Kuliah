#include <stdio.h>

void judul();
void hapusData(int arr[], int *size, int pos);

// Fungsi untuk menghapus elemen dari array
void hapusData(int arr[], int *size, int pos) {
	int i;
    if (pos >= 0 && pos < *size) { // Memeriksa apakah indeks valid
        for (i = pos; i < *size - 1; i++) { // Geser elemen ke kiri
            arr[i] = arr[i + 1];
        }
        (*size)--; // Kurangi ukuran array
        printf("Elemen pada posisi %d telah dihapus.\n", pos);
    } else {
        printf("Posisi tidak valid! Tidak dapat menghapus data.\n"); // Pesan kesalahan
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
	int i;
    int arr[] = {10, 20, 30, 40, 50}; // Deklarasi array
    int size = 5; // Ukuran awal array

    printf("Array sebelum penghapusan:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nMasukkan posisi elemen yang ingin dihapus (0-%d): ", size - 1);
    int pos;
    scanf("%d", &pos); // Input posisi elemen yang ingin dihapus

    hapusData(arr, &size, pos); // Memanggil fungsi untuk menghapus data

    printf("Array setelah penghapusan:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]); // Menampilkan array setelah penghapusan
    }

    return 0;
}

