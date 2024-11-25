#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3

struct WAKTU {
    int jj;
    int mm;
    int dd;
};

struct PENDAKI {
    char nama[30];
    char nomor[4];
    struct WAKTU mulai;
    struct WAKTU selesai;
    struct WAKTU durasi;
};

struct PASANGAN {
    struct PENDAKI *pendaki1;
    struct PENDAKI *pendaki2;
    struct WAKTU totalWaktu;
};

int totalDetik(struct WAKTU *w);
struct WAKTU hitungWaktu(int totalDetik);
void tambahData(struct PASANGAN **pasangan, int *isi);
struct PENDAKI *entriData();
void info(struct PASANGAN **pasangan, int isi);
void cariData(struct PASANGAN **pasangan, int isi);
void updateData(struct PASANGAN **pasangan, int isi);

int main() {
    struct PASANGAN *pasangan[N];
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
                tambahData(pasangan, &isi);
                break;
            case 2:
                info(pasangan, isi);
                break;
            case 3:
                cariData(pasangan, isi);
                break;
            case 4:
                updateData(pasangan, isi);
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

void tambahData(struct PASANGAN **pasangan, int *isi) {
    if (*isi < N) {
        pasangan[*isi] = (struct PASANGAN *)malloc(sizeof(struct PASANGAN));
        pasangan[*isi]->pendaki1 = entriData();
        pasangan[*isi]->pendaki2 = entriData();

        int total = totalDetik(&pasangan[*isi]->pendaki1->durasi) +
                    totalDetik(&pasangan[*isi]->pendaki2->durasi);

        pasangan[*isi]->totalWaktu = hitungWaktu(total);
        (*isi)++;
    } else {
        printf("Data penuh.\n");
    }
}

struct PENDAKI *entriData() {
    struct PENDAKI *pendaki = (struct PENDAKI *)malloc(sizeof(struct PENDAKI));
    char pemisah;
    int selisih;

    printf("Nama pendaki: ");
    scanf(" %[^\n]", pendaki->nama);
    printf("Nomor pendaki: ");
    scanf(" %[^\n]", pendaki->nomor);
    printf("Waktu mulai (hh:mm:ss): ");
    scanf("%d%c%d%c%d", &pendaki->mulai.jj, &pemisah, &pendaki->mulai.mm, &pemisah, &pendaki->mulai.dd);
    printf("Waktu selesai (hh:mm:ss): ");
    scanf("%d%c%d%c%d", &pendaki->selesai.jj, &pemisah, &pendaki->selesai.mm, &pemisah, &pendaki->selesai.dd);

    selisih = totalDetik(&pendaki->selesai) - totalDetik(&pendaki->mulai);
    pendaki->durasi = hitungWaktu(selisih);

    return pendaki;
}

void info(struct PASANGAN **pasangan, int isi) {
    printf("\nINFORMASI PASANGAN\n");
    printf("No  Pendaki 1          Durasi P1   Pendaki 2          Durasi P2   Total Waktu\n");
    for (int i = 0; i < isi; i++) {
        printf("%2d  %-15s %02d:%02d:%02d   %-15s %02d:%02d:%02d   %02d:%02d:%02d\n",
               i + 1,
               pasangan[i]->pendaki1->nama,
               pasangan[i]->pendaki1->durasi.jj, pasangan[i]->pendaki1->durasi.mm, pasangan[i]->pendaki1->durasi.dd,
               pasangan[i]->pendaki2->nama,
               pasangan[i]->pendaki2->durasi.jj, pasangan[i]->pendaki2->durasi.mm, pasangan[i]->pendaki2->durasi.dd,
               pasangan[i]->totalWaktu.jj, pasangan[i]->totalWaktu.mm, pasangan[i]->totalWaktu.dd);
    }
}

void cariData(struct PASANGAN **pasangan, int isi) {
    char nama[30];
    int found = 0;
    printf("Masukkan nama pendaki yang dicari: ");
    scanf(" %[^\n]", nama);//gets(nama);

    for (int i = 0; i < isi; i++) {
        if (strcmp(pasangan[i]->pendaki1->nama, nama) == 0 || strcmp(pasangan[i]->pendaki2->nama, nama) == 0) {
            printf("Data ditemukan pada pasangan %d:\n", i + 1);
            printf("Pendaki 1: %s\n", pasangan[i]->pendaki1->nama);
            printf("Pendaki 2: %s\n", pasangan[i]->pendaki2->nama);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Data tidak ditemukan.\n");
    }
}

void updateData(struct PASANGAN **pasangan, int isi) {
    char nama[30];
    int found = 0;

    printf("Masukkan nama pendaki yang ingin diupdate: ");
    scanf(" %[^\n]", nama);

    for (int i = 0; i < isi; i++) {
        struct PENDAKI *pendaki = NULL;
        if (strcmp(pasangan[i]->pendaki1->nama, nama) == 0) {
            pendaki = pasangan[i]->pendaki1;
        } else if (strcmp(pasangan[i]->pendaki2->nama, nama) == 0) {
            pendaki = pasangan[i]->pendaki2;
        }

        if (pendaki) {
            char pemisah;
            printf("Update waktu mulai (hh:mm:ss): ");
            scanf("%d%c%d%c%d", &pendaki->mulai.jj, &pemisah, &pendaki->mulai.mm, &pemisah, &pendaki->mulai.dd);
            printf("Update waktu selesai (hh:mm:ss): ");
            scanf("%d%c%d%c%d", &pendaki->selesai.jj, &pemisah, &pendaki->selesai.mm, &pemisah, &pendaki->selesai.dd);

            int selisih = totalDetik(&pendaki->selesai) - totalDetik(&pendaki->mulai);
            pendaki->durasi = hitungWaktu(selisih);

            int total = totalDetik(&pasangan[i]->pendaki1->durasi) +
                        totalDetik(&pasangan[i]->pendaki2->durasi);
            pasangan[i]->totalWaktu = hitungWaktu(total);

            printf("Data berhasil diupdate.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Data pendaki tidak ditemukan.\n");
    }
}