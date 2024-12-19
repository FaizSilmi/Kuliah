#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Untuk mengukur waktu eksekusi
#include <unistd.h>

#define MAX_BUFFER 1000 // Ukuran buffer untuk membaca file

// Fungsi untuk menghitung menggunakan fgets()
void hitungDenganFgets(FILE *file, int *jumlahKarakter, int *jumlahKata, int *jumlahBaris) {
    char buffer[MAX_BUFFER];
    char *kata;

    *jumlahKarakter = 0;
    *jumlahKata = 0;
    *jumlahBaris = 0;

    // Baca file baris per baris
    while (fgets(buffer, MAX_BUFFER, file) != NULL) {
        (*jumlahBaris)++;
        *jumlahKarakter += strlen(buffer); // Tambahkan panjang baris ke jumlah karakter
        kata = strtok(buffer, " \t\n"); // Tokenisasi string
        while (kata != NULL) {
            (*jumlahKata)++;
            kata = strtok(NULL, " \t\n"); // Ambil kata berikutnya
        }
    }
}

// Fungsi untuk menghitung menggunakan fscanf()
void hitungDenganFscanf(FILE *file, int *jumlahKarakter, int *jumlahKata, int *jumlahBaris) {
    char c;
    int inWord = 0;

    *jumlahKarakter = 0;
    *jumlahKata = 0;
    *jumlahBaris = 0;

    // Baca karakter demi karakter
    while ((c = fgetc(file)) != EOF) {
        (*jumlahKarakter)++;
        if (c == '\n') (*jumlahBaris)++; // Tambahkan baris jika karakter newline ditemukan

        if (c == ' ' || c == '\n' || c == '\t') {
            if (inWord) {
                (*jumlahKata)++;
                inWord = 0;
            }
        } else {
            inWord = 1; // Sedang berada dalam sebuah kata
        }
    }
    // Tambahkan kata terakhir jika ada
    if (inWord) (*jumlahKata)++;
}

int main() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {   // Fungsi ini berguna untuk mendeteksi direktori awal
         printf("File akan disimpan di direktori: %s\n", cwd);
    } else {
        perror("getcwd() error");
        return 1;
    }
    const char *newDirectory = "J:\\Kuliah\\Fundamental\\Tugas6"; //Fungsi ini berguna untuk mengubah file direktori
    if (chdir(newDirectory) == 0) {
    printf("Direktori kerja berhasil diubah ke: %s\n", newDirectory);
    } else {
        perror("Gagal mengubah direktori kerja");
    }
    printf("Nama Programmer: Muhammad Faiz Silmi\n");
    printf("NIM            : 24343099\n");
    
    FILE *file;
    char namaFile[100];
    int jumlahKarakter, jumlahKata, jumlahBaris;
    clock_t start, end;
    double waktuFgets, waktuFscanf;

    // Meminta pengguna memasukkan nama file
    printf("Masukkan nama file: ");
    scanf("%s", namaFile);

    // Membuka file untuk metode fgets()
    file = fopen(namaFile, "r");
    if (file == NULL) {
        printf("Gagal membuka file %s.\n", namaFile);
        return 1;
    }

    // Mengukur waktu untuk metode fgets()
    start = clock();
    hitungDenganFgets(file, &jumlahKarakter, &jumlahKata, &jumlahBaris);
    end = clock();
    waktuFgets = (double)(end - start) / CLOCKS_PER_SEC;

    // Menampilkan hasil metode fgets()
    printf("\n=== Menggunakan fgets() ===\n");
    printf("Jumlah karakter: %d\n", jumlahKarakter);
    printf("Jumlah kata: %d\n", jumlahKata);
    printf("Jumlah baris: %d\n", jumlahBaris);
    printf("Waktu eksekusi: %.5f detik\n", waktuFgets);

    fclose(file);

    // Membuka ulang file untuk metode fscanf()
    file = fopen(namaFile, "r");
    if (file == NULL) {
        printf("Gagal membuka file %s.\n", namaFile);
        return 1;
    }

    // Mengukur waktu untuk metode fscanf()
    start = clock();
    hitungDenganFscanf(file, &jumlahKarakter, &jumlahKata, &jumlahBaris);
    end = clock();
    waktuFscanf = (double)(end - start) / CLOCKS_PER_SEC;

    // Menampilkan hasil metode fscanf()
    printf("\n=== Menggunakan fscanf() ===\n");
    printf("Jumlah karakter: %d\n", jumlahKarakter);
    printf("Jumlah kata: %d\n", jumlahKata);
    printf("Jumlah baris: %d\n", jumlahBaris);
    printf("Waktu eksekusi: %.5f detik\n", waktuFscanf);

    fclose(file);

    // Menampilkan perbandingan waktu eksekusi
    printf("\n=== Perbandingan Waktu Eksekusi ===\n");
    printf("Waktu fgets() : %.5f detik\n", waktuFgets);
    printf("Waktu fscanf(): %.5f detik\n", waktuFscanf);

    return 0;
}