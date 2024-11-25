#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3
#define MAX_RONDE 5

struct WAKTU {
    int jj;
    int mm;
    int dd;
};

struct PEMAIN {
    char nama[30];
    char nomor[4];
    struct WAKTU waktuAwal;
    struct WAKTU durasiRonde[MAX_RONDE];
    int jumlahRonde;
    struct WAKTU totalDigunakan;
    struct WAKTU sisaWaktu;
};

int totalDetik(struct WAKTU *w);
struct WAKTU hitungWaktu(int totalDetik);
void tambahData(struct PEMAIN **pemain, int *isi);
struct PEMAIN *entriData();
void info(struct PEMAIN **pemain, int isi);
void cariData(struct PEMAIN **pemain, int isi);
void updateData(struct PEMAIN **pemain, int isi);

int main() {
    struct PEMAIN *pemain[N];
    int isi = 0;

    int pilihan;
    do {
        printf("\n1. Tambah Data\n");
        printf("2. Lihat Informasi\n");
        printf("3. Cari Data\n");
        printf("4. Update Data\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahData(pemain, &isi);
                break;
            case 2:
                info(pemain, isi);
                break;
            case 3:
                cariData(pemain, isi);
                break;
            case 4:
                updateData(pemain, isi);
                break;
        }
    } while (pilihan != 0);

    return 0;
}

int totalDetik(struct WAKTU *w) {
    return (w->jj * 3600 + w->mm * 60 + w->dd);
}

struct WAKTU hitungWaktu(int totalDetik) {
    struct WAKTU waktu;
    waktu.jj = totalDetik / 3600;
    waktu.mm = (totalDetik % 3600) / 60;
    waktu.dd = totalDetik % 60;
    return waktu;
}

void tambahData(struct PEMAIN **pemain, int *isi) {
    if (*isi < N) {
        pemain[*isi] = entriData();
        (*isi)++;
    } else {
        printf("Data penuh.\n");
    }
}

struct PEMAIN *entriData() {
    struct PEMAIN *temp = (struct PEMAIN *)malloc(sizeof(struct PEMAIN));
    char pemisah;
    int totalDurasi = 0;

    printf("Nama pemain: ");
    scanf(" %[^\n]", temp->nama);
    printf("Nomor pemain: ");
    scanf(" %[^\n]", temp->nomor);

    printf("Waktu awal (hh:mm:ss): ");
    scanf("%d%c%d%c%d", &temp->waktuAwal.jj, &pemisah, &temp->waktuAwal.mm, &pemisah, &temp->waktuAwal.dd);

    printf("Jumlah ronde yang dimainkan (maks %d): ", MAX_RONDE);
    scanf("%d", &temp->jumlahRonde);

    for (int i = 0; i < temp->jumlahRonde; i++) {
        printf("Durasi ronde %d (hh:mm:ss): ", i + 1);
        scanf("%d%c%d%c%d", &temp->durasiRonde[i].jj, &pemisah, &temp->durasiRonde[i].mm, &pemisah, &temp->durasiRonde[i].dd);

        totalDurasi += totalDetik(&temp->durasiRonde[i]);
    }

    temp->totalDigunakan = hitungWaktu(totalDurasi);
    int sisaDetik = totalDetik(&temp->waktuAwal) - totalDurasi;
    temp->sisaWaktu = hitungWaktu(sisaDetik);

    return temp;
}

void info(struct PEMAIN **pemain, int isi) {
    printf("\nINFORMASI TURNAMEN CATUR\n");
    printf("No  Nama Pemain      Total Digunakan   Sisa Waktu\n");
    for (int i = 0; i < isi; i++) {
        printf("%2d  %-15s  %02d:%02d:%02d       %02d:%02d:%02d\n",
               i + 1,
               pemain[i]->nama,
               pemain[i]->totalDigunakan.jj, pemain[i]->totalDigunakan.mm, pemain[i]->totalDigunakan.dd,
               pemain[i]->sisaWaktu.jj, pemain[i]->sisaWaktu.mm, pemain[i]->sisaWaktu.dd);
    }
}

void cariData(struct PEMAIN **pemain, int isi) {
    char nama[30];
    int found = 0;

    printf("Masukkan nama pemain yang dicari: ");
    scanf(" %[^\n]", nama);

    for (int i = 0; i < isi; i++) {
        if (strcmp(pemain[i]->nama, nama) == 0) {
            printf("Data ditemukan untuk pemain %s:\n", pemain[i]->nama);
            printf("Total Digunakan: %02d:%02d:%02d\n", pemain[i]->totalDigunakan.jj, pemain[i]->totalDigunakan.mm, pemain[i]->totalDigunakan.dd);
            printf("Sisa Waktu: %02d:%02d:%02d\n", pemain[i]->sisaWaktu.jj, pemain[i]->sisaWaktu.mm, pemain[i]->sisaWaktu.dd);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Data pemain tidak ditemukan.\n");
    }
}

void updateData(struct PEMAIN **pemain, int isi) {
    char nama[30];
    int found = 0;
    int ronde;
    char pemisah;

    printf("Masukkan nama pemain yang ingin diupdate: ");
    scanf(" %[^\n]", nama);

    for (int i = 0; i < isi; i++) {
        if (strcmp(pemain[i]->nama, nama) == 0) {
            printf("Masukkan nomor ronde yang ingin diupdate (1-%d): ", pemain[i]->jumlahRonde);
            scanf("%d", &ronde);

            if (ronde < 1 || ronde > pemain[i]->jumlahRonde) {
                printf("Nomor ronde tidak valid.\n");
                return;
            }

            ronde--; // Penyesuaian indeks
            printf("Update durasi ronde %d (hh:mm:ss): ", ronde + 1);
            scanf("%d%c%d%c%d", &pemain[i]->durasiRonde[ronde].jj, &pemisah, &pemain[i]->durasiRonde[ronde].mm, &pemisah, &pemain[i]->durasiRonde[ronde].dd);

            int totalDurasi = 0;
            for (int j = 0; j < pemain[i]->jumlahRonde; j++) {
                totalDurasi += totalDetik(&pemain[i]->durasiRonde[j]);
            }

            pemain[i]->totalDigunakan = hitungWaktu(totalDurasi);
            int sisaDetik = totalDetik(&pemain[i]->waktuAwal) - totalDurasi;
            pemain[i]->sisaWaktu = hitungWaktu(sisaDetik);

            printf("Data berhasil diupdate.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Data pemain tidak ditemukan.\n");
    }
}
