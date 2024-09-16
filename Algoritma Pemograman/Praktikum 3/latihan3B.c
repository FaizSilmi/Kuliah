/* 	Nama File		: latihan3B.c
	Programmer		: Muhammad Faiz SIilmi
	Tgl. pembuatan		: 10 September 2024
	Deskripsi		: program ini menampilkan teks	                            
*/

#include <stdio.h>

int main() {
    char text[100];

    printf("Masukkan beberapa baris teks :\n");

    // Membaca beberapa baris teks dengan gets()
    gets(text);

    printf("\nAnda memasukkan teks berikut:\n");

    // Menampilkan teks dengan puts()
    puts(text);

    return 0;
}

