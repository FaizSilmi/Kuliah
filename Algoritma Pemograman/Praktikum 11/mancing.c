#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3
#define MAX_IKAN 10

struct IKAN {
    double berat;
};

struct PESERTA {
    char nama[30];
    char nomor[4];
    struct IKAN ikan[MAX_IKAN];
    int jumlahIkan;
    double totalBerat;
    double ikanTerberat;
};

void tambahData(struct PESERTA **peserta, int *isi);
struct PESERTA *entriData();
void info(struct PESERTA **peserta, int isi);
void cariData(struct PESERTA **peserta, int isi);
void updateData(struct PESERTA **peserta, int isi);

int main() {
    struct PESERTA *peserta[N];
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
                tambahData(peserta, &isi);
                break;
            case 2:
                info(peserta, isi);
                break;
            case 3:
                cariData(peserta, isi);
                break;
            case 4:
                updateData(peserta, isi);
                break;
        }
    } while (pilihan != 0);

    return 0;
}

void tambahData(struct PESERTA **peserta, int *isi) {
    if (*isi < N) {
        peserta[*isi] = entriData();
        (*isi)++;
    } else {
        printf("Data penuh.\n");
    }
}

struct PESERTA *entriData() {
    struct PESERTA *temp = (struct PESERTA *)malloc(sizeof(struct PESERTA));
    double berat;

    printf("Nama peserta: ");
    scanf(" %[^\n]", temp->nama);
    printf("Nomor peserta: ");
    scanf(" %[^\n]", temp->nomor);

    printf("Jumlah ikan yang ditangkap (maks %d): ", MAX_IKAN);
    scanf("%d", &temp->jumlahIkan);

    temp->totalBerat = 0;
    temp->ikanTerberat = 0;

    for (int i = 0; i < temp->jumlahIkan; i++) {
        printf("Berat ikan ke-%d (kg): ", i + 1);
        scanf("%lf", &berat);

        temp->ikan[i].berat = berat;
        temp->totalBerat += berat;

        if (berat > temp->ikanTerberat) {
            temp->ikanTerberat = berat;
        }
    }

    return temp;
}

void info(struct PESERTA **peserta, int isi) {
    printf("\nINFORMASI PESERTA LOMBA MEMANCING\n");
    printf("No  Nama Peserta      Total Berat (kg)   Ikan Terberat (kg)\n");
    for (int i = 0; i < isi; i++) {
        printf("%2d  %-15s %10.2f           %10.2f\n",
               i + 1,
               peserta[i]->nama,
               peserta[i]->totalBerat,
               peserta[i]->ikanTerberat);
    }
}

void cariData(struct PESERTA **peserta, int isi) {
    char nama[30];
    int found = 0;
    printf("Masukkan nama peserta yang dicari: ");
    scanf(" %[^\n]", nama);

    for (int i = 0; i < isi; i++) {
        if (strcmp(peserta[i]->nama, nama) == 0) {
            printf("Data ditemukan untuk peserta %s:\n", peserta[i]->nama);
            printf("Total Berat: %.2f kg\n", peserta[i]->totalBerat);
            printf("Ikan Terberat: %.2f kg\n", peserta[i]->ikanTerberat);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Data peserta tidak ditemukan.\n");
    }
}

void updateData(struct PESERTA **peserta, int isi) {
    char nama[30];
    int found = 0;
    int indexIkan;
    double beratBaru;

    printf("Masukkan nama peserta yang ingin diupdate: ");
    scanf(" %[^\n]", nama);

    for (int i = 0; i < isi; i++) {
        if (strcmp(peserta[i]->nama, nama) == 0) {
            printf("Masukkan nomor ikan yang ingin diupdate (1-%d): ", peserta[i]->jumlahIkan);
            scanf("%d", &indexIkan);
            if (indexIkan < 1 || indexIkan > peserta[i]->jumlahIkan) {
                printf("Nomor ikan tidak valid.\n");
                return;
            }

            printf("Masukkan berat baru untuk ikan ke-%d (kg): ", indexIkan);
            scanf("%lf", &beratBaru);

            // Update total berat
            peserta[i]->totalBerat = peserta[i]->totalBerat - peserta[i]->ikan[indexIkan - 1].berat + beratBaru;
            peserta[i]->ikan[indexIkan - 1].berat = beratBaru;

            // Update ikan terberat
            peserta[i]->ikanTerberat = 0;
            for (int j = 0; j < peserta[i]->jumlahIkan; j++) {
                if (peserta[i]->ikan[j].berat > peserta[i]->ikanTerberat) {
                    peserta[i]->ikanTerberat = peserta[i]->ikan[j].berat;
                }
            }

            printf("Data berhasil diupdate.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Data peserta tidak ditemukan.\n");
    }
}
