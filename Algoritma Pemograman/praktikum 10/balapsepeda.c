/* 	
	Nama File			: Tugas1.c
	Programmer			: Muhammad Faiz Silmi 24343099
	Tgl. pembuatan	    : 10/12/2024
	Deskripsi			: Pengelolaan Waktu Perlombaan Balap Sepeda               
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 5
#define POS 5  // Jumlah pos pemeriksaan

// Struktur Data
struct PESERTA {
    char nama[30];
    char nomor[4];
};

struct WAKTU {
    int jj;
    int mm;
    int dd;
};

struct BALAP {
    struct PESERTA peserta;
    struct WAKTU datang[POS];
    struct WAKTU pergi[POS];
    struct WAKTU total;
};

// Deklarasi fungsi
void judul();
void selesai();
void menu(struct BALAP *balap[]);
int cekPenuh(struct BALAP *balap[]);
void tambahData(struct BALAP *balap[]);
struct BALAP *entriData();
int totalDetik(struct WAKTU *w);
void info(struct BALAP *balap[]);

// Var global posisi elemen
int isi = 0;

int main() {
    struct BALAP *balap[N] = {NULL};  // Array of pointer to BALAP
    judul();
    menu(balap);
    selesai();
    return 0;
}

// Definisi fungsi
void judul() {
    printf(" Pengelolaan Waktu Perlombaan Balap Sepeda\n");
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

int cekPenuh(struct BALAP *balap[]) {
    return (isi == N); // Mengembalikan true jika array penuh
}

void menu(struct BALAP *balap[]) {
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
                tambahData(balap);
                break;
            case 2:
                info(balap);
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

void tambahData(struct BALAP *balap[]) {
    char lagi;
    int penuh;

    penuh = cekPenuh(balap);

    do {
        if (penuh) {
            printf("\nData penuh...");
        } else {
            balap[isi] = entriData();
            isi++;
            penuh = cekPenuh(balap);
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

struct BALAP *entriData() {
    struct BALAP *temp = (struct BALAP *)malloc(sizeof(struct BALAP));
    char pemisah;
    int selisih, total_durasi = 0;

    printf("Ketikkan nama peserta: ");
    fgets(temp->peserta.nama, sizeof(temp->peserta.nama), stdin);
    temp->peserta.nama[strcspn(temp->peserta.nama, "\n")] = '\0';

    printf("Ketikkan nomor peserta: ");
    fgets(temp->peserta.nomor, sizeof(temp->peserta.nomor), stdin);
    temp->peserta.nomor[strcspn(temp->peserta.nomor, "\n")] = '\0';

    for (int i = 0; i < POS; i++) {
        printf("Ketikkan waktu datang di pos %d (ex, 07:05:10) : ", i + 1);
        scanf("%d%c%d%c%d", &temp->datang[i].jj, &pemisah,
                           &temp->datang[i].mm, &pemisah,
                           &temp->datang[i].dd);
        getchar();

        printf("Ketikkan waktu pergi dari pos %d (ex, 08:00:15): ", i + 1);
        scanf("%d%c%d%c%d", &temp->pergi[i].jj, &pemisah,
                           &temp->pergi[i].mm, &pemisah,
                           &temp->pergi[i].dd);
        getchar();

        // Hitung durasi per pos
        selisih = totalDetik(&temp->pergi[i]) - totalDetik(&temp->datang[i]);
        total_durasi += selisih;
    }

    // Konversi durasi total
    temp->total.jj = total_durasi / 3600;
    temp->total.mm = (total_durasi % 3600) / 60;
    temp->total.dd = (total_durasi % 3600) % 60;

    return temp;
}

int totalDetik(struct WAKTU *w) {
    return (w->jj * 3600 + w->mm * 60 + w->dd);
}

void info(struct BALAP *balap[]) {
    int i;

    if (isi > 0) {
        printf("\nINFORMASI LOMBA BALAP SEPEDA\n");
        printf("==================================================\n");
        printf("NO. NAMA PESERTA         WAKTU TOTAL\n");
        printf("==================================================\n");

        for (i = 0; i < isi; i++) {
            printf("%2d. %-15s  %02d:%02d:%02d\n",
                   i + 1,
                   balap[i]->peserta.nama,
                   balap[i]->total.jj, balap[i]->total.mm, balap[i]->total.dd);
        }

        printf("==================================================\n");
        printf("Tekan Enter...");
        getchar();
    } else {
        printf("\nBelum ada data yang tersedia.\n");
    }
}
