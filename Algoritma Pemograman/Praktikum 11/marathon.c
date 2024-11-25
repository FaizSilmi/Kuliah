#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3
#define POS 5

struct WAKTU {
    int jj;
    int mm;
    int dd;
};

struct PELARI {
    char nama[30];
    char nomor[4];
    struct WAKTU datang[POS];
    struct WAKTU pergi[POS];
    struct WAKTU totalDurasi;
};

int totalDetik(struct WAKTU *w);
struct WAKTU hitungWaktu(int totalDetik);
void tambahData(struct PELARI **pelari, int *isi);
struct PELARI *entriData();
void info(struct PELARI **pelari, int isi);
void cariData(struct PELARI **pelari, int isi);
void updateData(struct PELARI **pelari, int isi);

int main() {
    struct PELARI *pelari[N];
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
                tambahData(pelari, &isi);
                break;
            case 2:
                info(pelari, isi);
                break;
            case 3:
                cariData(pelari, isi);
                break;
            case 4:
                updateData(pelari, isi);
                break;
        }
    } while (pilihan != 0);

    return 0;
}

int totalDetik(struct WAKTU *w) {
    return w->jj * 3600 + w->mm * 60 + w->dd;
}

struct WAKTU hitungWaktu(int totalDetik) {
    struct WAKTU waktu;
    waktu.jj = totalDetik / 3600;
    waktu.mm = (totalDetik % 3600) / 60;
    waktu.dd = totalDetik % 60;
    return waktu;
}

void tambahData(struct PELARI **pelari, int *isi) {
    if (*isi < N) {
        pelari[*isi] = entriData();
        (*isi)++;
    } else {
        printf("Data penuh.\n");
    }
}

struct PELARI *entriData() {
    struct PELARI *temp = (struct PELARI *)malloc(sizeof(struct PELARI));
    char pemisah;
    int totalDurasi = 0;

    printf("Nama pelari: ");
    scanf(" %[^\n]", temp->nama);
    printf("Nomor pelari: ");
    scanf(" %[^\n]", temp->nomor);

    for (int i = 0; i < POS; i++) {
        printf("Waktu datang pos %d (hh:mm:ss): ", i + 1);
        scanf("%d%c%d%c%d", &temp->datang[i].jj, &pemisah, &temp->datang[i].mm, &pemisah, &temp->datang[i].dd);

        printf("Waktu pergi pos %d (hh:mm:ss): ", i + 1);
        scanf("%d%c%d%c%d", &temp->pergi[i].jj, &pemisah, &temp->pergi[i].mm, &pemisah, &temp->pergi[i].dd);

        int durasiPos = totalDetik(&temp->pergi[i]) - totalDetik(&temp->datang[i]);
        totalDurasi += durasiPos;
    }

    temp->totalDurasi = hitungWaktu(totalDurasi);
    return temp;
}

void info(struct PELARI **pelari, int isi) {
    printf("\nINFORMASI PELARI\n");
    printf("No  Nama                Total Durasi\n");
    for (int i = 0; i < isi; i++) {
        printf("%2d  %-20s %02d:%02d:%02d\n",
               i + 1,
               pelari[i]->nama,
               pelari[i]->totalDurasi.jj, pelari[i]->totalDurasi.mm, pelari[i]->totalDurasi.dd);
    }
}

void cariData(struct PELARI **pelari, int isi) {
    char nama[30];
    int found = 0;

    printf("Masukkan nama pelari yang dicari: ");
    scanf(" %[^\n]", nama);

    for (int i = 0; i < isi; i++) {
        if (strcmp(pelari[i]->nama, nama) == 0) {
            printf("Data ditemukan untuk pelari %s:\n", pelari[i]->nama);
            printf("Total Durasi: %02d:%02d:%02d\n",
                   pelari[i]->totalDurasi.jj, pelari[i]->totalDurasi.mm, pelari[i]->totalDurasi.dd);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Data pelari tidak ditemukan.\n");
    }
}

void updateData(struct PELARI **pelari, int isi) {
    char nama[30];
    int found = 0;
    int pos;
    char pemisah;

    printf("Masukkan nama pelari yang ingin diupdate: ");
    scanf(" %[^\n]", nama);

    for (int i = 0; i < isi; i++) {
        if (strcmp(pelari[i]->nama, nama) == 0) {
            printf("Masukkan nomor pos yang ingin diupdate (1-%d): ", POS);
            scanf("%d", &pos);
            if (pos < 1 || pos > POS) {
                printf("Pos tidak valid.\n");
                return;
            }

            pos--; // Penyesuaian indeks
            printf("Update waktu datang pos %d (hh:mm:ss): ", pos + 1);
            scanf("%d%c%d%c%d", &pelari[i]->datang[pos].jj, &pemisah, &pelari[i]->datang[pos].mm, &pemisah, &pelari[i]->datang[pos].dd);

            printf("Update waktu pergi pos %d (hh:mm:ss): ", pos + 1);
            scanf("%d%c%d%c%d", &pelari[i]->pergi[pos].jj, &pemisah, &pelari[i]->pergi[pos].mm, &pemisah, &pelari[i]->pergi[pos].dd);

            int totalDurasi = 0;
            for (int j = 0; j < POS; j++) {
                totalDurasi += totalDetik(&pelari[i]->pergi[j]) - totalDetik(&pelari[i]->datang[j]);
            }
            pelari[i]->totalDurasi = hitungWaktu(totalDurasi);
            printf("Data berhasil diupdate.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Data pelari tidak ditemukan.\n");
    }
}
