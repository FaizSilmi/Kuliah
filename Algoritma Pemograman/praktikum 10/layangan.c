/* 	
	Nama File			: Tugas1.c
	Programmer			: Muhammad Faiz Silmi 24343099
	Tgl. pembuatan	    : 10/12/2024
	Deskripsi			: Pengelolaan Waktu Perlombaan Layangan           
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define N 3
#define PI 3.14159265358979323846

// Struktur Data
struct PESERTA {
    char nama[30];
    char nomor[4];
};

struct LAYANGAN {
    struct PESERTA peserta;
    double panjangTali;
    double sudutElevasi;
    double ketinggian;
};

// Deklarasi fungsi
void judul();
void selesai();
void menu(struct LAYANGAN *layangan[]);
int cekPenuh(struct LAYANGAN *layangan[]);
void tambahData(struct LAYANGAN *layangan[]);
struct LAYANGAN *entriData();
double hitungKetinggian(double panjangTali, double sudutElevasi);
void info(struct LAYANGAN *layangan[]);

// Var global posisi elemen
int isi = 0;

int main() {
    struct LAYANGAN *layangan[N] = {NULL};  // Array of pointer to LAYANGAN
    judul();
    menu(layangan);
    selesai();
    return 0;
}

// Definisi fungsi
void judul() {
    printf(" Pengelolaan Waktu Perlombaan Layangan\n");
	printf("==============================\n");
	printf("Nama : Muhammad Faiz Silmi\n");
	printf("Nim  : 24343099\n");
	printf("==============================\n");
    printf("Tekan enter...");
    getchar();
}

void selesai() {
    printf("\nTerima kasih.... Sampai jumpa...\n");
    printf("Tekan enter...");
    getchar();
}

int cekPenuh(struct LAYANGAN *layangan[]) {
    return (isi == N); // Mengembalikan true jika array penuh
}

void menu(struct LAYANGAN *layangan[]) {
    int pilih;
    char jawab;

    do {
        printf("\nMENU PILIHAN\n");
        printf("--------------------------------\n");
        printf("1. Tambah Data\n");
        printf("2. Lihat Informasi\n");
        printf("0. Keluar\n");
        printf("--------------------------------\n");
        printf("Ketik Nomor pilihan Anda: ");
        scanf("%d", &pilih);
        getchar();

        switch (pilih) {
            case 1:
                tambahData(layangan);
                break;
            case 2:
                info(layangan);
                break;
            case 0:
                selesai();
                break;
            default:
                printf("\nNomor pilihan tidak ada...");
        }

        printf("\nMau mengulang lagi (Y/T): ");
        scanf(" %c", &jawab);
        getchar();
    } while (toupper(jawab) == 'Y');
}

void tambahData(struct LAYANGAN *layangan[]) {
    char lagi;
    int penuh;

    penuh = cekPenuh(layangan);

    do {
        if (penuh) {
            printf("\nData penuh...");
        } else {
            layangan[isi] = entriData();
            isi++;
            penuh = cekPenuh(layangan);
        }

        if (penuh) {
            printf("\nIni data terakhir...Tekan Enter...");
            lagi = 'T';
            getchar();
        } else {
            printf("\nTambah lagi (Y/T): ");
            scanf(" %c", &lagi);
            getchar();
        }
    } while (toupper(lagi) == 'Y');
}

struct LAYANGAN *entriData() {
    struct LAYANGAN *temp = (struct LAYANGAN *)malloc(sizeof(struct LAYANGAN));

    printf("Ketikkan nama peserta: ");
    fgets(temp->peserta.nama, sizeof(temp->peserta.nama), stdin);
    temp->peserta.nama[strcspn(temp->peserta.nama, "\n")] = '\0';

    printf("Ketikkan nomor peserta: ");
    fgets(temp->peserta.nomor, sizeof(temp->peserta.nomor), stdin);
    temp->peserta.nomor[strcspn(temp->peserta.nomor, "\n")] = '\0';

    printf("Ketikkan panjang tali layangan (meter): ");
    scanf("%lf", &temp->panjangTali);
    getchar();

    printf("Ketikkan sudut elevasi layangan (derajat): ");
    scanf("%lf", &temp->sudutElevasi);
    getchar();

    // Hitung ketinggian layangan
    temp->ketinggian = hitungKetinggian(temp->panjangTali, temp->sudutElevasi);

    return temp;
}

double hitungKetinggian(double panjangTali, double sudutElevasi) {
    double sudutRad = sudutElevasi * (PI / 180.0); // Konversi derajat ke radian
    return panjangTali * sin(sudutRad); // Menggunakan rumus trigonometri
}

void info(struct LAYANGAN *layangan[]) {
    int i;

    if (isi > 0) {
        printf("\nINFORMASI LOMBA LAYANGAN\n");
        printf("==================================================\n");
        printf("NO. NAMA PESERTA      PANJANG TALI   SUDUT ELEVASI   KETINGGIAN\n");
        printf("==================================================\n");
        }
}