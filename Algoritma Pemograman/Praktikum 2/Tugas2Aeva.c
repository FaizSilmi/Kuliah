/* 	
	Nama File		: latihan2A.c
	Programmer		: Muhammad Faiz Silmi
	Tgl. pembuatan		: 9 september 2024
	Deskripsi		: konverensi waktu jam ke total detik dan sebaliknya
*/

#include <stdio.h>

int main() {
    int jj, mm, dd;
    int jj2, mm2, dd2;
    int total_detik, totaldetik2;
    char titikDua;

    // Konversi jj:mm:dd ke total detik
    printf("Masukkan waktu (jj mm dd): ");
    scanf("%d%c%d%c%d", &jj, &titikDua, &mm, &titikDua, &dd);

    total_detik = jj * 3600 + mm * 60 + dd;
    printf("Total detik: %d\n", total_detik);

    // Konversi total detik ke format jj:mm:dd
    printf("Masukkan total detik: ");
    scanf("%d", &totaldetik2);

    jj2 = totaldetik2 / 3600;
    mm2 = (totaldetik2 % 3600) / 60;
    dd2 = ((totaldetik2 % 3600) % 60);

    printf("Waktu dalam format jj:mm:dd adalah %02d:%02d:%02d\n", jj2, mm2, dd2);

}
