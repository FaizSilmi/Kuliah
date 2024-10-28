/* 	
    Nama File		: Eva6a.c
	Programmer	    : Muhammad Faiz Silmi 24343099
	Tgl. pembuatan	: 14/10/2024                            
*/

#include <stdio.h>
#include <string.h>

int getColorValue(char* color) {
    if (strcmp(color, "hitam") == 0) return 0;
    if (strcmp(color, "coklat") == 0) return 1;
    if (strcmp(color, "merah") == 0) return 2;
    if (strcmp(color, "oren") == 0) return 3;
    if (strcmp(color, "kuning") == 0) return 4;
    if (strcmp(color, "hijau") == 0) return 5;
    if (strcmp(color, "biru") == 0) return 6;
    if (strcmp(color, "ungu") == 0) return 7;
    if (strcmp(color, "abu-abu") == 0) return 8;
    if (strcmp(color, "putih") == 0) return 9;
    return -1; // warna tidak valid
}

int main(){
    char warna1[20], warna2[20], warna3[20];
    int choice, nilai1, nilai2, faktor, nilaiResistor;
    do {
        printf("\nMenu:\n");
        printf("1. Lihat daftar warna dan nilainya\n");
        printf("2. Perhitungan nilai resistor\n");
        printf("3. Keluar\n");
        printf("Pilih tindakan (1/2/3): ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
            printf("black\t-0\n");
            printf("brown\t-1\n");
            printf("red\t-2\n");
            printf("orange\t-3\n");
            printf("yellow\t-4\n");
            printf("green\t-5\n");
            printf("blue\t-6\n");
            printf("violet\t-7\n");
            printf("gray\t-8\n");
            printf("white\t-9\n");
            break;
            case 2:
            printf("Masukkan warna resistor 1: ");
            scanf("%s", warna1);
            printf("Masukkan warna resistor 2: ");
            scanf("%s", warna2);
            printf("Masukkan warna faktor (warna 3): ");
            scanf("%s", warna3);

            nilai1 = getColorValue(warna1);
            nilai2 = getColorValue(warna2);
            faktor = getColorValue(warna3);

            nilaiResistor = (nilai1 * 10 + nilai2) * (1 << faktor);
            printf("Nilai resistor: %d ohm\n", nilaiResistor);
        }
    }while (choice != 3);
    return 0;
}