#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 3    // Jumlah peserta maksimum
#define MAX_BAHAN 10 // Jumlah bahan maksimum yang dapat digunakan per peserta

// Struktur Data
struct BAHAN {
    char nama[30];
    int durasi; // Durasi pemrosesan bahan dalam menit
};

struct PESERTA {
    char nama[30];
    char nomor[4];
    struct BAHAN bahan[MAX_BAHAN];
    int jumlahBahan;
    int totalWaktu;
    struct BAHAN bahanCepat;
};

// Deklarasi fungsi
void judul();
void selesai();
void menu(struct PESERTA *peserta[]);
int cekPenuh(struct PESERTA *peserta[]);
void tambahData(struct PESERTA *peserta[]);
struct PESERTA *entriData();
void info(struct PESERTA *peserta[]);

// Var global posisi elemen
int isi = 0;

int main() {
    struct PESERTA *peserta[N] = {NULL};  // Array of pointer to PESERTA
    judul();
    menu(peserta);
    selesai();
    return 0;
}

// Definisi fungsi
void judul() {
    printf("\nPENGELOLAAN LOMBA MEMASAK CEPAT DENGAN TANTANGAN BAHAN\n");
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

int cekPenuh(struct PESERTA *peserta[]) {
    return (isi == N); // Mengembalikan true jika array penuh
}

void menu(struct PESERTA *peserta[]) {
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
                tambahData(peserta);
                break;
            case 2:
                info(peserta);
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

void tambahData(struct PESERTA *peserta[]) {
    char lagi;
    int penuh;

    penuh = cekPenuh(peserta);

    do {
        if (penuh) {
            printf("\nData penuh...");
        } else {
            peserta[isi] = entriData();
            isi++;
            penuh = cekPenuh(peserta);
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

struct PESERTA *entriData() {
    struct PESERTA *temp = (struct PESERTA *)malloc(sizeof(struct PESERTA));
    int durasi;

    printf("Ketikkan nama peserta: ");
    fgets(temp->nama, sizeof(temp->nama), stdin);
    temp->nama[strcspn(temp->nama, "\n")] = '\0';

    printf("Ketikkan nomor peserta: ");
    fgets(temp->nomor, sizeof(temp->nomor), stdin);
    temp->nomor[strcspn(temp->nomor, "\n")] = '\0';

    printf("Ketikkan jumlah bahan yang digunakan (maksimum %d): ", MAX_BAHAN);
    scanf("%d", &temp->jumlahBahan);
    getchar();

    temp->totalWaktu = 0;
    temp->bahanCepat.durasi = 9999; // Inisialisasi dengan nilai besar untuk mencari bahan cepat

    for (int i = 0; i < temp->jumlahBahan; i++) {
        printf("Masukkan nama bahan ke-%d: ", i + 1);
        fgets(temp->bahan[i].nama, sizeof(temp->bahan[i].nama), stdin);
        temp->bahan[i].nama[strcspn(temp->bahan[i].nama, "\n")] = '\0';

        printf("Masukkan durasi pemrosesan bahan %s (dalam menit): ", temp->bahan[i].nama);
        scanf("%d", &durasi);
        getchar();

        temp->bahan[i].durasi = durasi;
        temp->totalWaktu += durasi;

        if (durasi < temp->bahanCepat.durasi) {
            temp->bahanCepat = temp->bahan[i];
        }
    }

    return temp;
}

void info(struct PESERTA *peserta[]) {
    int i;

    if (isi > 0) {
        printf("\nINFORMASI LOMBA MEMASAK CEPAT\n");
        printf("==========================================================================\n");
        printf("NO.  NAMA PESERTA      TOTAL WAKTU (MENIT)   BAHAN TERCEPAT (MENIT)\n");
        printf("==========================================================================\n");

        for (i = 0; i < isi; i++) {
            printf("%2d.  %-15s  %10d               %-15s (%d menit)\n",
                   i + 1,
                   peserta[i]->nama,
                   peserta[i]->totalWaktu,
                   peserta[i]->bahanCepat.nama,
                   peserta[i]->bahanCepat.durasi);
        }

        printf("==========================================================================\n");
        printf("Tekan Enter...");
        getchar();
    } else {
        printf("\nBelum ada data yang tersedia.\n");
    }
}
