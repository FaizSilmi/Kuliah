#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi struct untuk penyimpanan data mahasiswa
struct Mahasiswa {
    char nama[50];
    char nim[15];
    char jurusan[30];
};

int main() {
    struct Mahasiswa mahasiswa[100];
    int jumlahMahasiswa = 0;

    // Membaca file input.txt
    FILE *inputFile = fopen("I:\\Kuliah\\Kuliah\\Fundamental\\Modul9\\input.txt", "r");
    if (inputFile == NULL) {
        printf("File input.txt tidak dapat dibuka!\n");
        return 1;
    }

    // Membaca data dari file dan menimpannya dalam array of struct
    while (fscanf(inputFile, "%s %s %s", mahasiswa[jumlahMahasiswa].nama, mahasiswa[jumlahMahasiswa].nim, mahasiswa[jumlahMahasiswa].jurusan) != EOF) {
        jumlahMahasiswa++;
    }
    fclose(inputFile);

    // Menampilkan data yang telah dibaca
    printf("Data Mahasiswa dari file: \n");
    for (int i = 0; i < jumlahMahasiswa; i++) {
        printf("Nama: %s, NIM: %s, Jurusan: %s\n", mahasiswa[i].nama, mahasiswa[i].nim, mahasiswa[i].jurusan);
    }

    // Meminta input data mahasiswa baru
    printf("\nMasukkan data Mahasiswa baru;\n");
    printf("Nama: ");
    scanf("%s", mahasiswa[jumlahMahasiswa].nama);
    printf("NIM: ");
    scanf("%s", mahasiswa[jumlahMahasiswa].nim);
    printf("Jurusan: ");
    scanf("%s", mahasiswa[jumlahMahasiswa].jurusan);
    jumlahMahasiswa++;

    // Menulis seluruh data ke file output.txt
    FILE *outputFile = fopen("I:\\Kuliah\\Kuliah\\Fundamental\\Modul9\\output.txt", "w");
    if (outputFile == NULL) {
        printf("File output.txt tidak dapat dibuat!\n");
        return 1;
    }

    // Menulis header (judul kolom) ke file output.txt
    fprintf(outputFile, "Nama\t\tNIM\t\tJurusan\n");

    // Menulis data mahasiswa ke file output.txt
    for (int i = 0; i < jumlahMahasiswa; i++) {
        fprintf(outputFile, "%s\t%s\t%s\n", mahasiswa[i].nama, mahasiswa[i].nim, mahasiswa[i].jurusan);
    }
    fclose(outputFile);

    printf("\nData berhasil disimpan ke output.txt!\n");

    return 0;
}
