/* 	
	Nama File			: Tugas1.c
	Programmer			: Muhammad Faiz Silmi 24343099
	Tgl. pembuatan	    : 10/12/2024
	Deskripsi			: Pengelolaan Waktu Perlombaan Catur                
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 3   // Jumlah pemain maksimum
#define MAX_RONDE 5 // Jumlah ronde maksimum dalam turnamen

// Struktur Data
struct WAKTU {
    int jj; // Jam
    int mm; // Menit
    int dd; // Detik
};

struct PEMAIN {
    char nama[30];
    char nomor[4];
    struct WAKTU waktuAwal;
    struct WAKTU durasiRonde[MAX_RONDE];
    int jumlahRonde;
    struct WAKTU totalWaktuDigunakan;
    struct WAKTU sisaWaktu;
};

// Deklarasi fungsi
void judul();
void selesai();
void menu(struct PEMAIN *pemain[]);
int cekPenuh(struct PEMAIN *pemain[]);
void tambahData(struct PEMAIN *pemain[]);
struct PEMAIN *entriData();
int totalDetik(struct WAKTU *w);
struct WAKTU hitungWaktu(int totalDetik);
void info(struct PEMAIN *pemain[]);

// Var global posisi elemen
int isi = 0;

int main() {
    struct PEMAIN *pemain[N] = {NULL};  // Array of pointer to PEMAIN
    judul();
    menu(pemain);
    selesai();
    return 0;
}

// Definisi fungsi
void judul() {
    printf(" Pengelolaan Waktu Perlombaan Catur\n");
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

int cekPenuh(struct PEMAIN *pemain[]) {
    return (isi == N); // Mengembalikan true jika array penuh
}

void menu(struct PEMAIN *pemain[]) {
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
                tambahData(pemain);
                break;
            case 2:
                info(pemain);
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

void tambahData(struct PEMAIN *pemain[]) {
    char lagi;
    int penuh;

    penuh = cekPenuh(pemain);

    do {
        if (penuh) {
            printf("\nData penuh...");
        } else {
            pemain[isi] = entriData();
            isi++;
            penuh = cekPenuh(pemain);
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

struct PEMAIN *entriData() {
    struct PEMAIN *temp = (struct PEMAIN *)malloc(sizeof(struct PEMAIN));
    char pemisah;
    int totalDurasi = 0;

    printf("Ketikkan nama pemain: ");
    fgets(temp->nama, sizeof(temp->nama), stdin);
    temp->nama[strcspn(temp->nama, "\n")] = '\0';

    printf("Ketikkan nomor pemain: ");
    fgets(temp->nomor, sizeof(temp->nomor), stdin);
    temp->nomor[strcspn(temp->nomor, "\n")] = '\0';

    // Input waktu awal pemain
    printf("Ketikkan waktu awal (ex, 02:00:00): ");
    scanf("%d%c%d%c%d", &temp->waktuAwal.jj, &pemisah,
                       &temp->waktuAwal.mm, &pemisah,
                       &temp->waktuAwal.dd);
    getchar();

    printf("Ketikkan jumlah ronde yang dimainkan (maksimum %d): ", MAX_RONDE);
    scanf("%d", &temp->jumlahRonde);
    getchar();

    for (int i = 0; i < temp->jumlahRonde; i++) {
        printf("Masukkan durasi waktu di ronde %d (ex, 00:15:30): ", i + 1);
        scanf("%d%c%d%c%d", &temp->durasiRonde[i].jj, &pemisah,
                           &temp->durasiRonde[i].mm, &pemisah,
                           &temp->durasiRonde[i].dd);
        getchar();

        totalDurasi += totalDetik(&temp->durasiRonde[i]);
    }

    // Hitung total waktu yang digunakan
    temp->totalWaktuDigunakan = hitungWaktu(totalDurasi);

    // Hitung sisa waktu
    int waktuAwalDetik = totalDetik(&temp->waktuAwal);
    int sisaWaktuDetik = waktuAwalDetik - totalDurasi;
    temp->sisaWaktu = hitungWaktu(sisaWaktuDetik);

    return temp;
}

int totalDetik(struct WAKTU *w) {
    return (w->jj * 3600 + w->mm * 60 + w->dd);
}

struct WAKTU hitungWaktu(int totalDetik) {
    struct WAKTU waktu;
    waktu.jj = totalDetik / 3600;
    waktu.mm = (totalDetik % 3600) / 60;
    waktu.dd = (totalDetik % 3600) % 60;
    return waktu;
}

void info(struct PEMAIN *pemain[]) {
    int i;

    if (isi > 0) {
        printf("\nINFORMASI TURNAMEN CATUR\n");
        printf("=================================================================\n");
        printf("NO.  NAMA PEMAIN        TOTAL DIGUNAKAN  SISA WAKTU (JJ:MM:DD)\n");
        printf("=================================================================\n");

        for (i = 0; i < isi; i++) {
            printf("%2d.  %-15s  %02d:%02d:%02d         %02d:%02d:%02d\n",
                   i + 1,
                   pemain[i]->nama,
                   pemain[i]->totalWaktuDigunakan.jj, pemain[i]->totalWaktuDigunakan.mm, pemain[i]->totalWaktuDigunakan.dd,
                   pemain[i]->sisaWaktu.jj, pemain[i]->sisaWaktu.mm, pemain[i]->sisaWaktu.dd);
        }

        printf("=================================================================\n");
        printf("Tekan Enter...");
        getchar();
    } else {
        printf("\nBelum ada data yang tersedia.\n");
    }
}
