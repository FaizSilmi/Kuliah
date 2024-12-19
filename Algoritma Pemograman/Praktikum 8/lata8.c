/*
    Programmer    : Muhammad Faiz Silmi
    Nama File     : struct.c
    Mendefinisikan dan mendeklarasikan variabel struct
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MHS {
    char nama[30];
    char nim[5];
    double ipk;
};

// Deklarasi variabel struct
struct MHS mhs1;

// Deklarasi fungsi
// Fungsi untuk mengisi data struct
void isiData(const char *nm, const char *ni, double ip);
// Fungsi mencetak info data pada struct
void infoData(const struct MHS *mhs);

int main() {
    char namanya[30], nimnya[5];
    double ipknya;

    printf(" Mendefinisikan dan mendeklarasikan variabel struct \n");
    printf("====================================\n");
    printf("Nama : Muhammad Faiz Silmi\n");
    printf("Nim  : 24343099\n");
    printf("====================================\n");

    printf("Mengisi data struct:\n");
    printf("Ketikkan nama mahasiswa: ");
    fgets(namanya, sizeof(namanya), stdin);
    namanya[strcspn(namanya, "\n")] = 0; // Remove trailing newline character

    printf("Ketikkan NIM Mahasiswa: ");
    fgets(nimnya, sizeof(nimnya), stdin);
    nimnya[strcspn(nimnya, "\n")] = 0; // Remove trailing newline character

    printf("Ketikkan IPK Mahasiswa: ");
    if (scanf("%lf", &ipknya) != 1) {
        printf("Input IPK tidak valid.\n");
        return 1;
    }

    // Panggil fungsi mengisi data pada struct
    isiData(namanya, nimnya, ipknya);

    // Panggil fungsi untuk mencetak info mahasiswa
    infoData(&mhs1);

    return 0;
}

// Definisi fungsi
// Fungsi untuk mengisi data struct
void isiData(const char *nm, const char *ni, double ip) {
    strncpy(mhs1.nama, nm, sizeof(mhs1.nama) - 1);
    mhs1.nama[sizeof(mhs1.nama) - 1] = '\0'; // Ensure null-termination

    strncpy(mhs1.nim, ni, sizeof(mhs1.nim) - 1);
    mhs1.nim[sizeof(mhs1.nim) - 1] = '\0'; // Ensure null-termination

    mhs1.ipk = ip;
}

// Fungsi mencetak info data pada struct
void infoData(const struct MHS *mhs) {
    printf("\nInformasi Mahasiswa\n");
    printf("Nama Mahasiswa : %s\n", mhs->nama);
    printf("NIM Mahasiswa  : %s\n", mhs->nim);
    printf("IPK Mahasiswa  : %.2lf\n", mhs->ipk);
}
