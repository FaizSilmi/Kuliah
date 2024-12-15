/* 	Nama File		: latihan6B.c
	Programmer		: Muhammad Faiz Silmi 24343099
	Tgl. pembuatan	: 14/10/2024
	Deskripsi		: memilih operasi Pada Array
	                            
*/

#include <stdio.h>

// Fungsi untuk menampilkan elemen-elemen array
void displayArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size = 5; // Ukuran array
    int myArray[size]; // Deklarasi array dengan ukuran 5

    printf(" memilih operasi Pada Array \n");
    printf("=============================\n");
    printf("Nama : Muhammad Faiz Silmi\n");
    printf("Nim  : 24343099\n");
    printf("=============================\n");

    printf("Pilih operasi:\n");
    printf("1. Isi array\n");
    printf("2. Tampilkan array\n");
    printf("3. Ganti elemen array\n");
    printf("4. Keluar\n");

    int choice;
    do {
        printf("Masukkan pilihan (1/2/3/4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Mengisi elemen-elemen array
                printf("Masukkan %d elemen integer:\n", size);
                for (int i = 0; i < size; i++) {
                    scanf("%d", &myArray[i]);
                }
                break;
            case 2:
                // Menampilkan array
                displayArray(myArray, size);
                break;
            case 3:
                // Mengganti elemen array
                int indexToChange, newValue;
                printf("Masukkan indeks elemen yang ingin diganti: ");
                scanf("%d", &indexToChange);
                if (indexToChange >= 0 && indexToChange < size) {
                    printf("Masukkan nilai baru: ");
                    scanf("%d", &newValue);
                    myArray[indexToChange] = newValue;
                } else {
                    printf("Indeks tidak valid.\n");
                }
                break;
            case 4:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Coba lagi.\n");
        }
    } while (choice != 4);

    return 0;
}
