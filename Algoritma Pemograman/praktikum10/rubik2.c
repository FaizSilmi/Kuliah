#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 5

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

struct LOMBA {
    struct PESERTA peserta;
    struct WAKTU mulai;
    struct WAKTU akhir;
    struct WAKTU selisih;
};

// Deklarasi fungsi
void judul();
void selesai();
void menu(struct LOMBA *lomba[]);
int cekPenuh(struct LOMBA *lomba[]);
void tambahData(struct LOMBA *lomba[]);
struct LOMBA *entriData();
int totalDetik(struct WAKTU *w);
void info(struct LOMBA *lomba[]);

// Var global posisi elemen
int isi = 0;

int main() {
    struct LOMBA *lomba[N] = {NULL};  // Array of pointer to LOMBA, inisialisasi NULL
    judul();
    menu(lomba);
    selesai();
    return 0;
}

// Definisi fungsi
void judul() {
    printf("\nPENGELOLAAN LOMBA RUBIK\n");
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

int cekPenuh(struct LOMBA *lomba[]) {
    return (isi == N); // Mengembalikan true jika array penuh
}

void menu(struct LOMBA *lomba[]) {
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
                tambahData(lomba);
                break;
            case 2:
                info(lomba);
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

void tambahData(struct LOMBA *lomba[]) {
    char lagi;
    int penuh;

    penuh = cekPenuh(lomba);

    do {
        if (penuh) {
            printf("\nData penuh...");
        } else {
            // Tambahkan data menggunakan pointer yang dikembalikan oleh entriData
            lomba[isi] = entriData();
            isi++;
            penuh = cekPenuh(lomba);
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

struct LOMBA *entriData() {
    struct LOMBA *temp = (struct LOMBA *)malloc(sizeof(struct LOMBA));  // Alokasi memori bare untuk LOMBA
    char pemisah;
    int selisih;

    printf("Ketikkan nama peserta: ");
    fgets(temp->peserta.nama, sizeof(temp->peserta.nama), stdin);
    temp->peserta.nama[strcspn(temp->peserta.nama, "\n")] = '\0';  // Hilangkan newline

    printf("Ketikkan nomor peserta: ");
    fgets(temp->peserta.nomor, sizeof(temp->peserta.nomor), stdin);
    temp->peserta.nomor[strcspn(temp->peserta.nomor, "\n")] = '\0';

    printf("Ketikkan waktu start (ex, 07:05:10) : ");
    scanf("%d%c%d%c%d", &temp->mulai.jj, &pemisah,
                       &temp->mulai.mm, &pemisah,
                       &temp->mulai.dd);
    getchar();

    printf("Ketikkan waktu finish (ex, 08:00:15): ");
    scanf("%d%c%d%c%d", &temp->akhir.jj, &pemisah,
                       &temp->akhir.mm, &pemisah,
                       &temp->akhir.dd);
    getchar();

    // Hitung selisih waktu
    selisih = totalDetik(&temp->akhir) - totalDetik(&temp->mulai);

    // Konversi total detik ke format jam, menit, dan detik
    temp->selisih.jj = selisih / 3600;
    temp->selisih.mm = (selisih % 3600) / 60;
    temp->selisih.dd = (selisih % 3600) % 60;

    return temp;  // Kembalikan pointer ke struct LOMBA yang baru diisi
}

int totalDetik(struct WAKTU *w) {

    return (w->jj * 3600 + w->mm * 60 + w->dd);
}

void info(struct LOMBA *lomba[]) {
    int i;

    if (isi > 0) {
        printf("\nINFORMASI LOMBA\n");
        printf("==================================================\n");
        printf("NO. PESERTA          W START   W FINISH  DURASI\n");
        printf("==================================================\n");

        for (i = 0; i < isi; i++) {
            printf("%2d. %-15s  %02d:%02d:%02d  %02d:%02d:%02d  %02d:%02d:%02d\n",
                   i + 1,
                   lomba[i]->peserta.nama,
                   lomba[i]->mulai.jj, lomba[i]->mulai.mm, lomba[i]->mulai.dd,
                   lomba[i]->akhir.jj, lomba[i]->akhir.mm, lomba[i]->akhir.dd,
                   lomba[i]->selisih.jj, lomba[i]->selisih.mm, lomba[i]->selisih.dd);
        }

        printf("==================================================\n");
        printf("Tekan Enter...");
        getchar();
    } else {
        printf("\nBelum ada data yang tersedia.\n");
    }
}
