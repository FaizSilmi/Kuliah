/*
    Programmer    : Muhammad Faiz Silmi
    NIM           : 24343099
    Nama File     : struct1.c
    Mendefinisikan dan menggunakan variabel struct lokal
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi struct
struct MHS {
    char nama[30];
    char nim[5];
    double ipk;
};

// Deklarasi fungsi
// Fungsi untuk mengisi data struct
void isiData(struct MHS *mhsKu, const char *nm, const char *ni, double ip);
// Fungsi mencetak info data pada struct
void infoData(const struct MHS *mhsKu);

int main() {
    struct MHS myMhs;
    char namanya[30], nimnya[5];
    double ipknya;

    printf(" Mendefinisikan dan menggunakan variabel struct lokal \n");
    printf("====================================\n");
    printf("Nama : Muhammad Faiz Silmi\n");
    printf("NIM  : 24343099\n");
    printf("====================================\n");

    printf("Mengisi data struct:\n");
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

    // Panggil fungsi mengisi data pada struct
    isiData(&myMhs, namanya, nimnya, ipknya);

    // Panggil fungsi untuk mencetak info mahasiswa
    infoData(&myMhs);

    return 0;
}

// Definisi fungsi
// Fungsi untuk mengisi data struct
void isiData(struct MHS *mhsKu, const char *nm, const char *ni, double ip) {
    strncpy(mhsKu->nama, nm, sizeof(mhsKu->nama) - 1);
    mhsKu->nama[sizeof(mhsKu->nama) - 1] = '\0'; // Ensure null-termination

    strncpy(mhsKu->nim, ni, sizeof(mhsKu->nim) - 1);
    mhsKu->nim[sizeof(mhsKu->nim) - 1] = '\0'; // Ensure null-termination

    mhsKu->ipk = ip;
}

// Fungsi mencetak info data pada struct
void infoData(const struct MHS *mhsKu) {
    printf("\nInformasi Mahasiswa\n");
    printf("Nama Mahasiswa : %s\n", mhsKu->nama);
    printf("NIM Mahasiswa  : %s\n", mhsKu->nim);
    printf("IPK Mahasiswa  : %.2lf\n", mhsKu->ipk);
}
