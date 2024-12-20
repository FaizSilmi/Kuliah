/* 	
	Nama File			: Tugas1.c
	Programmer			: Muhammad Faiz Silmi 24343099
	Tgl. pembuatan	    : 10/12/2024
	Deskripsi			: Pengelolaan Waktu Perlombaan Masak      
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3
#define MAX_BAHAN 10

struct BAHAN {
    char nama[30];
    int durasi; // dalam menit
};

struct PESERTA {
    char nama[30];
    char nomor[4];
    struct BAHAN bahan[MAX_BAHAN];
    int jumlahBahan;
    int totalWaktu;
    struct BAHAN bahanCepat;
};

void tambahData(struct PESERTA **peserta, int *isi);
struct PESERTA *entriData();
void info(struct PESERTA **peserta, int isi);
void cariData(struct PESERTA **peserta, int isi);
void updateData(struct PESERTA **peserta, int isi);

int main() {
    struct PESERTA *peserta[N];
    int isi = 0;
    printf(" Pengelolaan Waktu Perlombaan Masak\n");
	printf("==============================\n");
	printf("Nama : Muhammad Faiz Silmi\n");
	printf("Nim  : 24343099\n");
	printf("==============================\n");
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
    int durasi;

    printf("Nama peserta: ");
    scanf(" %[^\n]", temp->nama);
    printf("Nomor peserta: ");
    scanf(" %[^\n]", temp->nomor);

    printf("Jumlah bahan yang digunakan (maks %d): ", MAX_BAHAN);
    scanf("%d", &temp->jumlahBahan);

    temp->totalWaktu = 0;
    temp->bahanCepat.durasi = 9999; // nilai awal maksimum

    for (int i = 0; i < temp->jumlahBahan; i++) {
        printf("Nama bahan ke-%d: ", i + 1);
        scanf(" %[^\n]", temp->bahan[i].nama);
        printf("Durasi pemrosesan bahan %s (menit): ", temp->bahan[i].nama);
        scanf("%d", &durasi);

        temp->bahan[i].durasi = durasi;
        temp->totalWaktu += durasi;

        if (durasi < temp->bahanCepat.durasi) {
            temp->bahanCepat = temp->bahan[i];
        }
    }

    return temp;
}

void info(struct PESERTA **peserta, int isi) {
    printf("\nINFORMASI PESERTA LOMBA MEMASAK CEPAT\n");
    printf("No  Nama Peserta      Total Waktu (menit)   Bahan Tercepat (menit)\n");
    for (int i = 0; i < isi; i++) {
        printf("%2d  %-15s  %10d             %-15s (%d menit)\n",
               i + 1,
               peserta[i]->nama,
               peserta[i]->totalWaktu,
               peserta[i]->bahanCepat.nama,
               peserta[i]->bahanCepat.durasi);
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
            printf("Total Waktu: %d menit\n", peserta[i]->totalWaktu);
            printf("Bahan Tercepat: %s (%d menit)\n", peserta[i]->bahanCepat.nama, peserta[i]->bahanCepat.durasi);
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
    int indexBahan;
    int durasiBaru;

    printf("Masukkan nama peserta yang ingin diupdate: ");
    scanf(" %[^\n]", nama);

    for (int i = 0; i < isi; i++) {
        if (strcmp(peserta[i]->nama, nama) == 0) {
            printf("Masukkan nomor bahan yang ingin diupdate (1-%d): ", peserta[i]->jumlahBahan);
            scanf("%d", &indexBahan);

            if (indexBahan < 1 || indexBahan > peserta[i]->jumlahBahan) {
                printf("Nomor bahan tidak valid.\n");
                return;
            }

            printf("Masukkan durasi baru untuk bahan ke-%d (menit): ", indexBahan);
            scanf("%d", &durasiBaru);

            // Update total waktu
            peserta[i]->totalWaktu = peserta[i]->totalWaktu - peserta[i]->bahan[indexBahan - 1].durasi + durasiBaru;
            peserta[i]->bahan[indexBahan - 1].durasi = durasiBaru;

            // Update bahan tercepat
            peserta[i]->bahanCepat.durasi = 9999;
            for (int j = 0; j < peserta[i]->jumlahBahan; j++) {
                if (peserta[i]->bahan[j].durasi < peserta[i]->bahanCepat.durasi) {
                    peserta[i]->bahanCepat = peserta[i]->bahan[j];
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
