#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 3    // Jumlah peserta maksimum
#define MAX_IKAN 10  // Jumlah ikan maksimum yang dapat ditangkap per peserta

// Struktur Data
struct IKAN {
    double berat; // Berat ikan dalam kilogram
};

struct PESERTA {
    char nama[30];
    char nomor[4];
    struct IKAN ikan[MAX_IKAN];
    int jumlahIkan;
    double totalBerat;
    double ikanTerberat;
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
    printf("\nPENGELOLAAN LOMBA MEMANCING TERBERAT\n");
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
    double berat;
    
    printf("Ketikkan nama peserta: ");
    fgets(temp->nama, sizeof(temp->nama), stdin);
    temp->nama[strcspn(temp->nama, "\n")] = '\0';

    printf("Ketikkan nomor peserta: ");
    fgets(temp->nomor, sizeof(temp->nomor), stdin);
    temp->nomor[strcspn(temp->nomor, "\n")] = '\0';

    printf("Ketikkan jumlah ikan yang ditangkap (maksimum %d): ", MAX_IKAN);
    scanf("%d", &temp->jumlahIkan);
    getchar();

    // Inisialisasi total berat dan ikan terberat
    temp->totalBerat = 0;
    temp->ikanTerberat = 0;

    for (int i = 0; i < temp->jumlahIkan; i++) {
        printf("Masukkan berat ikan ke-%d (kg): ", i + 1);
        scanf("%lf", &berat);
        getchar();

        temp->ikan[i].berat = berat;
        temp->totalBerat += berat;

        if (berat > temp->ikanTerberat) {
            temp->ikanTerberat = berat;
        }
    }

    return temp;
}

void info(struct PESERTA *peserta[]) {
    int i;

    if (isi > 0) {
        printf("\nINFORMASI LOMBA MEMANCING\n");
        printf("=================================================================\n");
        printf("NO.  NAMA PESERTA      TOTAL BERAT (KG)      IKAN TERBERAT (KG)\n");
        printf("=================================================================\n");

        for (i = 0; i < isi; i++) {
            printf("%2d.  %-15s  %10.2f             %10.2f\n",
                   i + 1,
                   peserta[i]->nama,
                   peserta[i]->totalBerat,
                   peserta[i]->ikanTerberat);
        }

        printf("=================================================================\n");
        printf("Tekan Enter...");
        getchar();
    } else {
        printf("\nBelum ada data yang tersedia.\n");
    }
}
