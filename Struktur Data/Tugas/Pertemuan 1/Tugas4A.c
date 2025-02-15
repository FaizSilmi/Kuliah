#include <stdio.h>

void judul();
void updateData(int arr[], int pos, int size, int newValue);

// Fungsi untuk memperbarui elemen array
void updateData(int arr[], int pos, int size, int newValue) {
    if (pos >= 0 && pos < size) { // Memeriksa apakah indeks valid
        arr[pos] = newValue; // Mengupdate nilai elemen
        printf("Data pada posisi %d telah diperbarui menjadi: %d\n", pos, arr[pos]);
    } else {
        printf("Posisi tidak valid! Tidak dapat memperbarui data.\n"); // Pesan kesalahan
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
    int size = sizeof(arr) / sizeof(arr[0]); // Menghitung ukuran array

    printf("Masukkan posisi data yang ingin diupdate (0-%d): ", size - 1);
    int pos;
    scanf("%d", &pos); // Input posisi yang ingin diupdate

    printf("Masukkan nilai baru: ");
    int newValue;
    scanf("%d", &newValue); // Input nilai baru

    updateData(arr, pos, size, newValue); // Memanggil fungsi untuk memperbarui data

    printf("Array setelah update:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]); // Menampilkan array setelah update
    }

    return 0;
}

