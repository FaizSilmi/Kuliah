/* 	
    Nama File		: latihan6A.c
	Programmer		: Muhammad Faiz Silmi 24343099
	Tgl. pembuatan	: 14/10/2024
	Deskripsi		: memasukkan 5 elemen integer ke dalam array, 
*/
#include <stdio.h>

// Fungsi untuk menampilkan elemen-elemen array
void displayArray(int arr[], int size) {
    printf("Array: ");
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size = 5; // Ukuran array
    int myArray[size]; // Deklarasi array dengan ukuran 5

    // Mengisi elemen-elemen array
    printf("\nMasukkan %d elemen integer:\n", size);
    int i;
    for (i = 0; i < size; i++) {
        scanf("%d", &myArray[i]);
    }

    // Menampilkan array sebelum perubahan
    displayArray(myArray, size);

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

    // Menampilkan array setelah perubahan
    displayArray(myArray, size);

    return 0;
}
