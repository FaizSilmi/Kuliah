/* 	Nama File		: latihan5D.c
	Programmer	    : Muhammad Faiz Silmi 24343099
	Tgl. pembuatan	: 07/10/2024
	Deskripsi		: program manajemen tugas	                            
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk menampilkan judul program
void judul() {
    printf("===== Aplikasi Manajemen Tugas =====\n");
}

// Fungsi untuk mengambil input judul, deskripsi, dan tenggat waktu tugas
void inputTugas(char judul[], char deskripsi[], char tenggatWaktu[]) {
    printf("Masukkan judul tugas: ");
    scanf(" %[^\n]s", judul);

    printf("Masukkan deskripsi tugas: ");
    scanf(" %[^\n]s", deskripsi);

    printf("Masukkan tenggat waktu (dd/mm/yyyy): ");
    scanf(" %[^\n]s", tenggatWaktu);
}

// Fungsi untuk memilih menu
int pilihMenu() {
    int pilihan;
    printf("Menu:\n");
    printf("1. Tambah Tugas\n");
    printf("2. Tampilkan Daftar Tugas\n");
    printf("3. Keluar\n");
    printf("Pilih tindakan: ");
    scanf("%d", &pilihan);
    return pilihan;
}

// Fungsi untuk menampilkan info tugas
void tampilkanInfoTugas(char judul[], char deskripsi[], char tenggatWaktu[], int selesai) {
    printf("Judul: %s\n", judul);
    printf("Deskripsi: %s\n", deskripsi);
    printf("Tenggat Waktu: %s\n", tenggatWaktu);
    printf("Status: %s\n", selesai ? "Selesai" : "Belum Selesai");
    printf("\n");
}

// Fungsi untuk menentukan status tugas (selesai atau belum selesai)
int nilai() {
    int selesai;
    printf("Apakah tugas ini selesai? (1 untuk Ya, 0 untuk Tidak): ");
    scanf("%d", &selesai);
    return selesai;
}

int main() {
    char judul[100];
    char deskripsi[500];
    char tenggatWaktu[20];
    int selesai = 0; // Tugas baru selalu belum selesai
    int jumlahTugas = 0;
    int pilihan;

    do {
        judul();
        pilihan = pilihMenu();

        switch (pilihan) {
            case 1:
                if (jumlahTugas < 100) { // Maksimum 100 tugas
                    inputTugas(judul, deskripsi, tenggatWaktu);
                    selesai = nilai();
                    printf("Tugas telah ditambahkan.\n");
                    jumlahTugas++;
                } else {
                    printf("Maksimum jumlah tugas telah tercapai.\n");
                }
                break;
            case 2:
                if (jumlahTugas == 0) {
                    printf("Belum ada tugas.\n");
                } else {
                    judul();
                    printf("========== Daftar Tugas ==========\n");
                    tampilkanInfoTugas(judul, deskripsi, tenggatWaktu, selesai);
                }
                break;
            case 3:
                printf("Terima kasih! Sampai jumpa.\n");
                exit(0);
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (1);

    return 0;
}
