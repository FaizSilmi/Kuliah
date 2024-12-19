/* 	
	Nama File       : Tugas1.c
	Programmer      : Muhammad Faiz Silmi 24343099
	Tgl. pembuatan  : 10/12/2024
	Deskripsi       : Pengelolaan Waktu Perlombaan Rubik                  
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 3

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

// Function declarations
void judul();
void selesai();
void menu();
int cekPenuh(struct LOMBA m[]);
void tambahData(struct LOMBA lmb[]);
struct LOMBA entriData();
int totalDetik(struct WAKTU w);
void info(struct LOMBA lmb[]);

// Global variable for array position
int isi = 0;

int main() {
	judul();
	menu();
	selesai();
	return 0;
}

void judul() {
	printf("Pengelolaan Waktu Perlombaan Rubik\n");
	printf("==================================\n");
	printf("Nama : Muhammad Faiz Silmi\n");
	printf("NIM  : 24343099\n");
	printf("==================================\n\n");
	printf("Tekan Enter untuk melanjutkan...\n");
	getchar();
}

void selesai() {
	printf("\nTerima kasih.... Sampai jumpa...\n");
	printf("Tekan Enter untuk keluar...");
	getchar();
}

int cekPenuh(struct LOMBA m[]) {
	return isi == N;
}

void menu() {
	int pilih;
	struct LOMBA rubik[N];
	char jawab;

	do {
		printf("\nMENU PILIHAN\n");
		printf("--------------------------------\n");
		printf("1. Tambah Data\n");
		printf("2. Lihat Informasi\n");
		printf("0. Keluar\n");
		printf("--------------------------------\n");
		printf("Masukkan nomor pilihan Anda: ");
		scanf("%d", &pilih);
		getchar(); // Clear newline from input buffer

		switch (pilih) {
			case 1: 
				tambahData(rubik); 
				break;
			case 2: 
				info(rubik); 
				break;
			case 0: 
				return;
			default: 
				printf("\nNomor pilihan tidak valid.\n");
		}

		printf("\nMau mengulang lagi (Y/T)? ");
		scanf(" %c", &jawab);
		getchar(); // Clear newline
	} while (toupper(jawab) == 'Y');
}

void tambahData(struct LOMBA lmb[]) {
	char lagi;
	int penuh = cekPenuh(lmb);

	do {
		if (penuh) {
			printf("\nData penuh...\n");
			break;
		}

		// Enter data
		lmb[isi] = entriData();
		isi++;
		penuh = cekPenuh(lmb);

		if (penuh) {
			printf("\nIni data terakhir... Tekan Enter...\n");
			getchar();
			break;
		} else {
			printf("\nTambah lagi (Y/T)? ");
			scanf(" %c", &lagi);
			getchar(); // Clear newline
		}
	} while (toupper(lagi) == 'Y');
}

struct LOMBA entriData() {
	struct LOMBA temp;
	char pemisah;
	int selisih;

	printf("\nMasukkan nama peserta: ");
	fgets(temp.peserta.nama, sizeof(temp.peserta.nama), stdin);
	temp.peserta.nama[strcspn(temp.peserta.nama, "\n")] = '\0'; // Remove newline

	printf("Masukkan nomor peserta: ");
	fgets(temp.peserta.nomor, sizeof(temp.peserta.nomor), stdin);
	temp.peserta.nomor[strcspn(temp.peserta.nomor, "\n")] = '\0'; // Remove newline

	printf("Masukkan waktu start (hh:mm:ss): ");
	scanf("%d%c%d%c%d", &temp.mulai.jj, &pemisah, &temp.mulai.mm, &pemisah, &temp.mulai.dd);

	printf("Masukkan waktu finish (hh:mm:ss): ");
	scanf("%d%c%d%c%d", &temp.akhir.jj, &pemisah, &temp.akhir.mm, &pemisah, &temp.akhir.dd);
	getchar(); // Clear newline

	// Calculate time difference
	selisih = totalDetik(temp.akhir) - totalDetik(temp.mulai);
	temp.selisih.jj = selisih / 3600;
	temp.selisih.mm = (selisih % 3600) / 60;
	temp.selisih.dd = (selisih % 3600) % 60;

	return temp;
}

int totalDetik(struct WAKTU w) {
	return w.jj * 3600 + w.mm * 60 + w.dd;
}

void info(struct LOMBA lmb[]) {
	if (isi == 0) {
		printf("\nData tidak ada.\n");
		return;
	}

	printf("\nINFORMASI LOMBA\n");
	printf("==================================================\n");
	printf("NO. PESERTA          W START   W FINISH  DURASI\n");
	printf("==================================================\n");

	for (int i = 0; i < isi; i++) {
		printf("%2d. %-15s  %02d:%02d:%02d  %02d:%02d:%02d  %02d:%02d:%02d\n",
			i + 1,
			lmb[i].peserta.nama,
			lmb[i].mulai.jj, lmb[i].mulai.mm, lmb[i].mulai.dd,
			lmb[i].akhir.jj, lmb[i].akhir.mm, lmb[i].akhir.dd,
			lmb[i].selisih.jj, lmb[i].selisih.mm, lmb[i].selisih.dd
		);
	}

	printf("==================================================\n");
	printf("Tekan Enter untuk melanjutkan...");
	getchar();
}
