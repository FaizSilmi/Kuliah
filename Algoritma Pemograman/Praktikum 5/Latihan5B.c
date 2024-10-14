/* 	Nama File		: latihan5B.c
	Programmer		: Muhammad Faiz Silmi 24343099
	Tgl. pembuatan	: 07/10/2024
	Deskripsi		: program yang menerapkan dua fungsi: satu tanpa parameter   
                      dan nilai balik, dan satu dengan parameter dan tanpa nilai 
                      alik.	                            
*/

#include <stdio.h>

// Fungsi tanpa parameter dan nilai balik
void sapaPengguna() {
    printf("Halo! Selamat datang di program sederhana.\n");
}

// Fungsi dengan parameter dan tanpa nilai balik
void tambahkanDuaAngka(int a, int b) {
    int hasil = a + b;
    printf("Hasil penambahan %d dan %d adalah: %d\n", a, b, hasil);
}

int main() {
    sapaPengguna(); // Memanggil fungsi tanpa parameter dan nilai balik
    int x = 5;
    int y = 7;

    tambahkanDuaAngka(x, y); // Memanggil fungsi dengan parameter dan                tanpa nilai balik

    return 0;
}
