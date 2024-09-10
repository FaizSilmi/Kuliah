/* 	Nama File		: latihan3A.c
	Programmer		: Muhammad Faiz Silmi
	Tgl. pembuatan	: tuliskan tanggal hari praktikum anda
	Deskripsi		: program ini represtasi input output berformat	                            
*/

#include <stdio.h>

int main() {
    char name[50];
    int age;

    // Input dengan format
    printf("Masukkan nama Anda: ");
    scanf("%s", name);
    printf("Masukkan usia Anda: ");
    scanf("%d", &age);

    // Menampilkan informasi dengan format
    printf("Halo, %s! Anda berusia %d tahun.\n", name, age);

    return 0;
}

