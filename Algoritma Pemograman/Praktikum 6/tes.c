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

int main() {
    char warna1[20], warna2[20], warna3[20];
    int nilai1, nilai2, faktor, nilaiResistor;

    printf("Masukkan warna resistor 1: ");
    scanf("%s", warna1);
    printf("Masukkan warna resistor 2: ");
    scanf("%s", warna2);
    printf("Masukkan warna faktor (warna 3): ");
    scanf("%s", warna3);

    nilai1 = getColorValue(warna1);
    nilai2 = getColorValue(warna2);
    faktor = getColorValue(warna3);

    if (nilai1 == -1 || nilai2 == -1 || faktor == -1) {
        printf("Warna yang dimasukkan tidak valid.\n");
        return 1;
    }

    // Menghitung nilai resistor
    nilaiResistor = (nilai1 * 10 + nilai2) * (1 << faktor);
    printf("Nilai resistor: %d ohm\n", nilaiResistor);

    return 0;
}
