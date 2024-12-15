/* 	Nama File		  : tugas1.c
	Programmer	   	: Muhammad Faiz Silmi 24343099
	Tgl. pembuatan	: 09/11/2024
	Deskripsi		    : Mengakses Elemen Array Dua Dimensi Menggunakan Pointer
*/
#include <stdio.h>

void biodata(){
    printf("Mengakses Elemen Array Dua Dimensi Menggunakan Pointer\n");
    printf("==========================================================\n");
    printf("Nama : Muhammad Faiz Silmi\n");
    printf("Nim  : 24343099\n");
    printf("==============================\n");
}
int main() {
    biodata();
    int array[3][3] = {  // Deklarasi dan inisialisasi array dua dimensi
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int *ptr;  // Deklarasi pointer
    ptr = &array[0][0];  // Inisialisasi pointer ke elemen pertama array

    printf("Elemen-elemen dalam array dua dimensi:\n");
    
    // Mengakses dan menampilkan elemen-elemen array menggunakan pointer
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Menggunakan pointer aritmatika untuk mengakses elemen array
            printf("Elemen di baris %d kolom %d: %d\n", i, j, *(ptr + i * 3 + j));
        }
    }

    return 0;
}
