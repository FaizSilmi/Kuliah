/*
    Programmer    : Muhammad Faiz Silmi
    NIM           : 24343099
    Nama File     : struct5.c
    Menggunakan array of struct dan fungsi yang mengembalikan var struct
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3

typedef struct {
    char nama[30];
    char nim[5];
    double ipk;
} MHS;

// Deklarasi fungsi
// Fungsi untuk mengisi data struct dan mengembalikan var struct
MHS isiData(const char *nm, const char *ni, double ip);
// Fungsi mencetak info data pada struct
void infoData(const MHS mhsKu[]);

int main() {
    MHS myMhs[N];
    int i;
    char namanya[30], nimnya[5];
    double ipknya;

    printf(" Menggunakan array of struct dan fungsi yang mengembalikan var struct \n");
    printf("====================================\n");
    printf("Nama : Muhammad Faiz Silmi\n");
    printf("NIM  : 24343099\n");
    printf("====================================\n");

    printf("Mengisi data struct:\n");
    for (i = 0; i < N; i++) {
        printf("\nData Mahasiswa ke-%d\n", i + 1);

        printf("Ketikkan nama mahasiswa: ");
        fgets(namanya, sizeof(namanya), stdin);
        namanya[strcspn(namanya, "\n")] = 0; // Remove trailing newline

        printf("Ketikkan NIM Mahasiswa: ");
        fgets(nimnya, sizeof(nimnya), stdin);
        nimnya[strcspn(nimnya, "\n")] = 0; // Remove trailing newline

        printf("Ketikkan IPK Mahasiswa: ");
        if (scanf("%lf", &ipknya) != 1) {
            printf("Input IPK tidak valid.\n");
            return 1;
        }
        getchar(); // Clear leftover newline character from input buffer

        // Panggil fungsi mengisi data pada struct
        myMhs[i] = isiData(namanya, nimnya, ipknya);
    }

    // Panggil fungsi untuk mencetak info mahasiswa
    printf("\n");
    infoData(myMhs);

    return 0;
}

// Fungsi untuk mengisi data struct dan mengembalikan var struct
MHS isiData(const char *nm, const char *ni, double ip) {
    MHS mhs;
    strncpy(mhs.nama, nm, sizeof(mhs.nama) - 1);
    mhs.nama[sizeof(mhs.nama) - 1] = '\0'; // Ensure null-termination

    strncpy(mhs.nim, ni, sizeof(mhs.nim) - 1);
    mhs.nim[sizeof(mhs.nim) - 1] = '\0'; // Ensure null-termination

    mhs.ipk = ip;
    return mhs;
}

// Fungsi mencetak info data pada struct
void infoData(const MHS mhsKu[]) {
    int i;
    printf("Informasi Mahasiswa:\n");
    for (i = 0; i < N; i++) {
        printf("\nMahasiswa ke-%d\n", i + 1);
        printf("Nama Mahasiswa : %s\n", mhsKu[i].nama);
        printf("NIM Mahasiswa  : %s\n", mhsKu[i].nim);
        printf("IPK Mahasiswa  : %.2lf\n", mhsKu[i].ipk);
    }
}
