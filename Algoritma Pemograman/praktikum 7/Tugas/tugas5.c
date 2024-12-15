/* 	Nama File		  : tugas1.c
	Programmer	   	: Muhammad Faiz Silmi 24343099
	Tgl. pembuatan	: 09/11/2024
	Deskripsi		    : Menukar Elemen Array Menggunakan Pointer
*/
#include <stdio.h>
#include <string.h>

void biodata(){
    printf("Menukar Elemen Array Menggunakan Pointer\n");
    printf("=============================\n");
    printf("Nama : Muhammad Faiz Silmi\n");
    printf("Nim  : 24343099\n");
    printf("==============================\n");
}
// Definisi struct Mahasiswa
struct Mahasiswa {
    char nama[50];
    char nim[20];
    float nilai;
};

// Fungsi untuk mengisi data mahasiswa
void isiDataMahasiswa(struct Mahasiswa *mhs, const char *nama, const char *nim, float nilai) {
    strcpy(mhs->nama, nama);
    strcpy(mhs->nim, nim);
    mhs->nilai = nilai;
}

// Fungsi untuk memodifikasi data mahasiswa melalui pointer
void modifikasiDataMahasiswa(struct Mahasiswa *mhs, const char *namaBaru, float nilaiBaru) {
    strcpy(mhs->nama, namaBaru); // Mengubah nama
    mhs->nilai = nilaiBaru;      // Mengubah nilai
}

int main() {
    biodata();
    // Deklarasi struct Mahasiswa
    struct Mahasiswa mhs;

    // Mengisi data awal mahasiswa
    isiDataMahasiswa(&mhs, "Ali Ahmad", "2431001", 85.0);

    // Menampilkan data awal mahasiswa
    printf("Data Awal Mahasiswa:\n");
    printf("Nama : %s\n", mhs.nama);
    printf("NIM  : %s\n", mhs.nim);
    printf("Nilai: %.2f\n\n", mhs.nilai);

    // Memodifikasi data mahasiswa
    modifikasiDataMahasiswa(&mhs, "Ali Abdullah", 90.0);

    // Menampilkan data setelah dimodifikasi
    printf("Data Setelah Dimodifikasi:\n");
    printf("Nama : %s\n", mhs.nama);
    printf("NIM  : %s\n", mhs.nim);
    printf("Nilai: %.2f\n", mhs.nilai);

    return 0;
}
