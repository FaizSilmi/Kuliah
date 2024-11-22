#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 3   // Jumlah pelari
#define POS 5 // Jumlah pos pengisian energi

// Struktur Data
struct WAKTU {
    int jj; // Jam
    int mm; // Menit
    int dd; // Detik
};

struct PELARI {
    char nama[30];
    char nomor[4];
    struct WAKTU datang[POS];
    struct WAKTU pergi[POS];
    struct WAKTU durasiTotal;
};

// Deklarasi fungsi
void judul();
void selesai();
void menu(struct PELARI *pelari[]);
int cekPenuh(struct PELARI *pelari[]);
void tambahData(struct PELARI *pelari[]);
struct PELARI *entriData();
int totalDetik(struct WAKTU *w);
void info(struct PELARI *pelari[]);

// Var global posisi elemen
int isi = 0;

int main() {
    struct PELARI *pelari[N] = {NULL};  // Array of pointer to PELARI
    judul();
    menu(pelari);
    selesai();
    return 0;
}

// Definisi fungsi
void judul() {
    printf("\nPENGELOLAAN LOMBA MARATON DENGAN POS PENGISIAN ENERGI\n");
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

int cekPenuh(struct PELARI *pelari[]) {
    return (isi == N); // Mengembalikan true jika array penuh
}

void menu(struct PELARI *pelari[]) {
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
                tambahData(pelari);
                break;
            case 2:
                info(pelari);
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

void tambahData(struct PELARI *pelari[]) {
    char lagi;
    int penuh;

    penuh = cekPenuh(pelari);

    do {
        if (penuh) {
            printf("\nData penuh...");
        } else {
            pelari[isi] = entriData();
            isi++;
            penuh = cekPenuh(pelari);
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

struct PELARI *entriData() {
    struct PELARI *temp = (struct PELARI *)malloc(sizeof(struct PELARI));
    char pemisah;
    int selisih, total_durasi = 0;

    printf("Ketikkan nama pelari: ");
    fgets(temp->nama, sizeof(temp->nama), stdin);
    temp->nama[strcspn(temp->nama, "\n")] = '\0';

    printf("Ketikkan nomor pelari: ");
    fgets(temp->nomor, sizeof(temp->nomor), stdin);
    temp->nomor[strcspn(temp->nomor, "\n")] = '\0';

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

        // Hitung durasi di setiap pos
        selisih = totalDetik(&temp->pergi[i]) - totalDetik(&temp->datang[i]);
        total_durasi += selisih;
    }

    // Konversi durasi total ke format jam, menit, detik
    temp->durasiTotal.jj = total_durasi / 3600;
    temp->durasiTotal.mm = (total_durasi % 3600) / 60;
    temp->durasiTotal.dd = total_durasi % 60;

    return temp;
}

int totalDetik(struct WAKTU *w) {
    return (w->jj * 3600 + w->mm * 60 + w->dd);
}

void info(struct PELARI *pelari[]) {
    int i;

    if (isi > 0) {
        printf("\nINFORMASI LOMBA MARATON\n");
        printf("==================================================\n");
        printf("NO. NAMA PELARI      TOTAL DURASI (JJ:MM:DD)\n");
        printf("==================================================\n");

        for (i = 0; i < isi; i++) {
            printf("%2d. %-15s  %02d:%02d:%02d\n",
                   i + 1,
                   pelari[i]->nama,
                   pelari[i]->durasiTotal.jj, pelari[i]->durasiTotal.mm, pelari[i]->durasiTotal.dd);
        }

        printf("==================================================\n");
        printf("Tekan Enter...");
        getchar();
    } else {
        printf("\nBelum ada data yang tersedia.\n");
    }
}
