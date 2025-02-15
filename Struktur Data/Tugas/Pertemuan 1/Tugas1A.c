#include <stdio.h>

void judul();
void traversalArray(int arr[],int size);

int main() {
	judul();
    int arr[] = {10, 20, 30, 40, 50}; // Deklarasi array
    int size = sizeof(arr) / sizeof(arr[0]); // Menghitung jumlah elemen dalam array

    printf("Hasil Traversal Array:\n");
    traversalArray(arr, size); // Memanggil fungsi traversal untuk mencetak elemen array

    return 0;
}
void judul(){
	printf("====================================\n");
    printf("Nama   	      : Muhammad Faiz Silmi\n");
    printf("NIM           : 24343099\n");
    printf("Matakuliah    : Struktur Data\n");
    printf("Nama Program  : Traversal Array 1 Dimensi\n");
    printf("====================================\n\n\n");
}
// Fungsi untuk traversal array
void traversalArray(int arr[], int size) {
	int i;
    for (i = 0;i < size; i++) { // Iterasi melalui setiap elemen array
        printf("Elemen ke-%d: %d\n", i, arr[i]);
    }
}
