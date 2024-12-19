/* 	
	Nama File			: Tugas1.c
	Programmer			: Muhammad Faiz Silmi 24343099
	Tgl. pembuatan	    : 10/12/2024
	Deskripsi			: Pengelolaan Waktu Perlombaan Panjat Tebing             
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 3

// Struktur Data
struct WAKTU {
    int jj; // Jam
    int mm; // Menit
    int dd; // Detik
};

struct PENDAKI {
    char nama[30];
    char nomor[4];
    struct WAKTU mulai;
    struct WAKTU selesai;
    struct WAKTU durasi;
};

struct PASANGAN {
    struct PENDAKI pendaki1;
    struct PENDAKI pendaki2;
    struct WAKTU totalWaktu;
};

// Deklarasi fungsi
void judul();
void selesai();
void menu(struct PASANGAN *pasangan[]);
int cekPenuh(struct PASANGAN *pasangan[]);
void tambahData(struct PASANGAN *pasangan[]);
struct PASANGAN *entriData();
int totalDetik(struct WAKTU *w);
void info(struct PASANGAN *pasangan[]);

// Var global posisi elemen
int isi = 0;

int main() {
    struct PASANGAN *pasangan[N] = {NULL};  // Array of pointer to PASANGAN
    judul();
    menu(pasangan);
    selesai();
    return 0;
}

// Definisi fungsi
void judul() {
    printf(" Pengelolaan Waktu Perlombaan Panjat Tebing\n");
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

int cekPenuh(struct PASANGAN *pasangan[]) {
    return (isi == N); // Mengembalikan true jika array penuh
}

void menu(struct PASANGAN *pasangan[]) {
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
                tambahData(pasangan);
                break;
            case 2:
                info(pasangan);
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

void tambahData(struct PASANGAN *pasangan[]) {
    char lagi;
    int penuh;

    penuh = cekPenuh(pasangan);

    do {
        if (penuh) {
            printf("\nData penuh...");
        } else {
            pasangan[isi] = entriData();
            isi++;
            penuh = cekPenuh(pasangan);
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

struct PASANGAN *entriData() {
    struct PASANGAN *temp = (struct PASANGAN *)malloc(sizeof(struct PASANGAN));
    char pemisah;
    int selisih1, selisih2;

    // Data Pendaki 1
    printf("Ketikkan nama Pendaki 1: ");
    fgets(temp->pendaki1.nama, sizeof(temp->pendaki1.nama), stdin);
    temp->pendaki1.nama[strcspn(temp->pendaki1.nama, "\n")] = '\0';

    printf("Ketikkan nomor Pendaki 1: ");
    fgets(temp->pendaki1.nomor, sizeof(temp->pendaki1.nomor), stdin);
    temp->pendaki1.nomor[strcspn(temp->pendaki1.nomor, "\n")] = '\0';

    printf("Ketikkan waktu mulai Pendaki 1 (ex, 07:05:10): ");
    scanf("%d%c%d%c%d", &temp->pendaki1.mulai.jj, &pemisah,
                       &temp->pendaki1.mulai.mm, &pemisah,
                       &temp->pendaki1.mulai.dd);
    getchar();

    printf("Ketikkan waktu selesai Pendaki 1 (ex, 08:00:15): ");
    scanf("%d%c%d%c%d", &temp->pendaki1.selesai.jj, &pemisah,
                       &temp->pendaki1.selesai.mm, &pemisah,
                       &temp->pendaki1.selesai.dd);
    getchar();

    // Hitung durasi Pendaki 1
    selisih1 = totalDetik(&temp->pendaki1.selesai) - totalDetik(&temp->pendaki1.mulai);
    temp->pendaki1.durasi.jj = selisih1 / 3600;
    temp->pendaki1.durasi.mm = (selisih1 % 3600) / 60;
    temp->pendaki1.durasi.dd = selisih1 % 60;

    // Data Pendaki 2
    printf("Ketikkan nama Pendaki 2: ");
    fgets(temp->pendaki2.nama, sizeof(temp->pendaki2.nama), stdin);
    temp->pendaki2.nama[strcspn(temp->pendaki2.nama, "\n")] = '\0';

    printf("Ketikkan nomor Pendaki 2: ");
    fgets(temp->pendaki2.nomor, sizeof(temp->pendaki2.nomor), stdin);
    temp->pendaki2.nomor[strcspn(temp->pendaki2.nomor, "\n")] = '\0';

    printf("Ketikkan waktu mulai Pendaki 2 (ex, 07:05:10): ");
    scanf("%d%c%d%c%d", &temp->pendaki2.mulai.jj, &pemisah,
                       &temp->pendaki2.mulai.mm, &pemisah,
                       &temp->pendaki2.mulai.dd);
    getchar();

    printf("Ketikkan waktu selesai Pendaki 2 (ex, 08:00:15): ");
    scanf("%d%c%d%c%d", &temp->pendaki2.selesai.jj, &pemisah,
                       &temp->pendaki2.selesai.mm, &pemisah,
                       &temp->pendaki2.selesai.dd);
    getchar();

    // Hitung durasi Pendaki 2
    selisih2 = totalDetik(&temp->pendaki2.selesai) - totalDetik(&temp->pendaki2.mulai);
    temp->pendaki2.durasi.jj = selisih2 / 3600;
    temp->pendaki2.durasi.mm = (selisih2 % 3600) / 60;
    temp->pendaki2.durasi.dd = selisih2 % 60;

    // Hitung total waktu pasangan
    int total = selisih1 + selisih2;
    temp->totalWaktu.jj = total / 3600;
    temp->totalWaktu.mm = (total % 3600) / 60;
    temp->totalWaktu.dd = total % 60;

    return temp;
}

int totalDetik(struct WAKTU *w) {
    return (w->jj * 3600 + w->mm * 60 + w->dd);
}

void info(struct PASANGAN *pasangan[]) {
    int i;

    if (isi > 0) {
        printf("\nINFORMASI PASANGAN LOMBA PANJAT TEBING\n");
        printf("==================================================\n");
        printf("NO. PASANGAN             DURASI P1    DURASI P2    TOTAL WAKTU\n");
        printf("==================================================\n");

        for (i = 0; i < isi; i++) {
            printf("%2d. %-15s  %02d:%02d:%02d   %02d:%02d:%02d   %02d:%02d:%02d\n",
                   i + 1,
                   pasangan[i]->pendaki1.nama,
                   pasangan[i]->pendaki1.durasi.jj, pasangan[i]->pendaki1.durasi.mm, pasangan[i]->pendaki1.durasi.dd,
                   pasangan[i]->pendaki2.durasi.jj, pasangan[i]->pendaki2.durasi.mm, pasangan[i]->pendaki2.durasi.dd,
                   pasangan[i]->totalWaktu.jj, pasangan[i]->totalWaktu.mm, pasangan[i]->totalWaktu.dd);
        }

        printf("==================================================\n");
        printf("Tekan Enter...");
        getchar();
    } else {
        printf("\nBelum ada data yang tersedia.\n");
    }
}
