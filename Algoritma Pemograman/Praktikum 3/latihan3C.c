/* 	Nama File		: latihan3C.c
	Programmer		: Muhammad Faiz Silmi
	Tgl. pembuatan	: tuliskan tanggal hari praktikum anda
	Deskripsi		: program ini membaca karakter getchar()	                            
*/

#include <stdio.h>

int main() {
    char ch;

    printf("Tolong masukkan sebuah karakter:\n");
    ch = getche(); // membaca dan menampilkan karakter
    printf("\nAnda memasukkan karakter berikut: %c \n", ch);

    return 0;
}

