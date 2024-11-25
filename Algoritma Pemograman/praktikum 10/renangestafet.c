#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 3
#define P 4  // Empat perenang per tim

// Struktur Data
struct PERENANG {
    char nama[30];
    char nomor[4];
};

struct WAKTU {
    int jj;
    int mm;
    int dd;
};

struct TIM {
    struct PERENANG perenang[P];
    struct WAKTU mulai[P];
    struct WAKTU akhir[P];
    struct WAKTU total;
};

// Deklarasi fungsi
void judul();
void selesai();
void menu(struct TIM *tim[]);
int cekPenuh(struct TIM *tim[]);
void tambahData(struct TIM *tim[]);
struct TIM *entriData();
int totalDetik(struct WAKTU *w);
void info(struct TIM *tim[]);

// Var global posisi elemen
int isi = 0;

int main() {
    struct TIM *tim[N] = {NULL};  // Array of pointer to TIM
    judul();
    menu(tim);
    selesai();
    return 0;
}

// Definisi fungsi
void judul() {
    printf("\nPENGELOLAAN LOMBA RENANG ESTAFET 4x100 METER\n");
    printf("Programmer: Anu\n");
    printf("==============================\n");
    printf("Tekan enter...");
    getchar();
}

void selesai() {
    printf("\nTerima kasih.... Sampai jumpa...\n");
    printf("Tekan enter...");
    getchar();
}

int cekPenuh(struct TIM *tim[]) {
    return (isi == N); // Mengembalikan true jika array penuh
}

void menu(struct TIM *tim[]) {
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
                tambahData(tim);
                break;
            case 2:
                info(tim);
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

void tambahData(struct TIM *tim[]) {
    char lagi;
    int penuh;

    penuh = cekPenuh(tim);

    do {
        if (penuh) {
            printf("\nData penuh...");
        } else {
            tim[isi] = entriData();
            isi++;
            penuh = cekPenuh(tim);
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

struct TIM *entriData() {
    struct TIM *temp = (struct TIM *)malloc(sizeof(struct TIM));
    char pemisah;
    int selisih, total_durasi = 0;

    for (int i = 0; i < P; i++) {
        printf("Ketikkan nama perenang %d: ", i + 1);
        fgets(temp->perenang[i].nama, sizeof(temp->perenang[i].nama), stdin);
        temp->perenang[i].nama[strcspn(temp->perenang[i].nama, "\n")] = '\0';

        printf("Ketikkan nomor perenang %d: ", i + 1);
        fgets(temp->perenang[i].nomor, sizeof(temp->perenang[i].nomor), stdin);
        temp->perenang[i].nomor[strcspn(temp->perenang[i].nomor, "\n")] = '\0';

        printf("Ketikkan waktu start perenang %d (ex, 07:05:10) : ", i + 1);
        scanf("%d%c%d%c%d", &temp->mulai[i].jj, &pemisah,
                           &temp->mulai[i].mm, &pemisah,
                           &temp->mulai[i].dd);
        getchar();

        printf("Ketikkan waktu finish perenang %d (ex, 08:00:15): ", i + 1);
        scanf("%d%c%d%c%d", &temp->akhir[i].jj, &pemisah,
                           &temp->akhir[i].mm, &pemisah,
                           &temp->akhir[i].dd);
        getchar();

        // Hitung durasi per perenang
        selisih = totalDetik(&temp->akhir[i]) - totalDetik(&temp->mulai[i]);
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

void info(struct TIM *tim[]) {
    int i;

    if (isi > 0) {
        printf("\nINFORMASI TIM RENANG ESTAFET\n");
        printf("==================================================\n");
        printf("NO. NAMA TIM         WAKTU TOTAL\n");
        printf("==================================================\n");

        for (i = 0; i < isi; i++) {
            printf("%2d. %-15s  %02d:%02d:%02d\n",
                   i + 1,
                   tim[i]->total.jj, tim[i]->total.mm, tim[i]->total.dd);
        }

        printf("==================================================\n");
        printf("Tekan Enter...");
        getchar();
    } else {
        printf("\nBelum ada data yang tersedia.\n");
    }
}
