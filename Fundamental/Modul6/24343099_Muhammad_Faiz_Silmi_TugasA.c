/*  
     Nama File		: A.c
	Programmer		: Muhammad Faiz Silmi
	Tgl. pembuatan	: 11/09/2024
    Deskripsi    : Menghitung Panjang String
*/
#include <stdio.h>
#include <string.h>

// Deklarasi fungsi hitungPanjangString
int hitungPanjangString(char str[]);

void biodata(){
	printf("Menghitung Panjang String\n");
	printf("=================================================================\n");
	printf("Nama : Muhammad Faiz Silmi\n");
	printf("Nim  : 24343099\n");
	printf("==============================\n");
}
int main() {
    biodata();
    char str[100];

    // Meminta input string dari pengguna
    printf("Masukkan sebuah string: ");
    fgets(str, sizeof(str), stdin);

    // Menghilangkan newline di akhir string jika ada
    str[strcspn(str, "\n")] = '\0';

    // Memanggil fungsi hitungPanjangString dan menampilkan hasilnya
    int panjang = hitungPanjangString(str);
    printf("Panjang string yang dimasukkan: %d\n", panjang);

    return 0;
}

// Definisi fungsi hitungPanjangString
int hitungPanjangString(char str[]) {
    return strlen(str); // Menggunakan strlen untuk menghitung panjang string
}
