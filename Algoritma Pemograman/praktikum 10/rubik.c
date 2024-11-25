#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3

struct PESERTA{
	char nama[30];
	char nomor[4];
};

struct WAKTU{
	int jj;
	int mm;
	int dd;
};

struct LOMBA{
	struct PESERTA peserta;
	struct WAKTU mulai;
	struct WAKTU akhir;
	struct WAKTU selisih;
};

//deklarasi fungsi
void judul();
void selesai();
void menu();
int cekPenuh(struct LOMBA m[]);
void tambahData(struct LOMBA lmb[]);
struct LOMBA entriData();
int totalDetik(struct WAKTU w);
void info(struct LOMBA lmb[]);

//var global posisi elemen
int isi=0;//karena belum ada isi array

int main(){
	judul();
	menu();
	selesai();
	
	return 0;
}

//definisi fungsi
void judul(){
	printf("\nPENGELOLAAN LOMBA RUBIK\n");
	printf("Programmer: Anu\n");
	printf("==============================\n");
	printf("Tekan enter...");
	getch();
}

void selesai(){
	printf("\nTerima kasih.... Sampai jumpa...\n");
	printf("Tekan enter...");
	getch();
}

int cekPenuh(struct LOMBA m[]){
	if(isi == N) return 1;
	else return 0; 
}

void menu(){
	int pilih;
	struct LOMBA rubik[N];
	char jawab;
	
	do{
		printf("MENU PILIHAN\n");
		printf("--------------------------------\n");
		printf("1. Tambah Data\n");
		printf("2. Lihat Informasi\n");
		printf("0. Keluar\n");
		printf("--------------------------------\n");
		printf("Ketik Nomor pilihan Anda: ");
		scanf("%d", &pilih); fflush(stdin);
		
		switch(pilih){
			case 1: tambahData(rubik); break;
			case 2: info(rubik); break;
			case 0: selesai(); break;
			default: printf("\nNomor pilihan tidak ada...");
		}
		
		printf("\nMau mengulang lagi (Y/T): ");
		scanf("%c", &jawab);
	} while(toupper(jawab) == 'Y');
}

void tambahData(struct LOMBA lmb[]) {
	char lagi;
	int penuh;
	
	penuh = cekPenuh(lmb);
	
	do{
		//cek dulu array, penuh tidak?
		if(penuh){
			printf("\nData penuh...");
		}
		else{
			//entrikan data
			lmb[isi] = entriData();
			isi++;
			penuh = cekPenuh(lmb);
		}
		//tambah lagi gak? lakukan jika masih bisa
		if(penuh){
			printf("\nIni data terakhir...Tekan Enter...");
			lagi = 'T';
			getch();
		}
		else{
			printf("\nTambah lagi (Y/T): ");
			scanf("%c", &lagi); fflush(stdin);
		}
	}while(toupper(lagi)=='Y');
}

struct LOMBA entriData(){
	struct LOMBA temp;
	char pemisah;
	int selisih;
	
	printf("Ketikkan nama peserta : ");
	gets(temp.peserta.nama); fflush(stdin);
	printf("Ketikkan nomor peserta: ");
	gets(temp.peserta.nomor); fflush(stdin);
	printf("Ketikkan waktu start (ex, 07:05:10) : ");
	scanf("%d%c%d%c%d", &temp.mulai.jj, &pemisah,
				&temp.mulai.mm, &pemisah,
				&temp.mulai.dd); fflush(stdin);
	printf("Ketikkan waktu finish (ex, 08:00:15): ");
	scanf("%d%c%d%c%d", &temp.akhir.jj, &pemisah,
				&temp.akhir.mm, &pemisah,
				&temp.akhir.dd); fflush(stdin);
	//isikan selisih waktu
	selisih = totalDetik(temp.akhir) - totalDetik(temp.mulai);
	//ubah total detik ke format j, m, d
	temp.selisih.jj = selisih/3600;
	temp.selisih.mm = selisih%3600/60;
	temp.selisih.dd = selisih%3600%60;
	
	return temp;
}

int totalDetik(struct WAKTU w){
	int ttl;
	
	ttl = w.jj * 3600 + w.mm *60 + w.dd;
	
	return ttl;
}

void info(struct LOMBA lmb[]){
	int i;
	int js, ms, ds;
	int jf, mf, df;
	int jb, mb, db;
	char nm[20];
	
	if(isi == 0){
	     printf("Data Tidak Ada\n");
	}	

	if(isi){
		//cetak isinya
		printf("\nINFORMASI LOMBA\n");
		printf("==================================================\n");
		printf("NO. PESERTA          W START   W FINISH  DURASI\n");
		printf("==================================================\n");
		for(i=0;i<isi;i++){
			js = lmb[i].mulai.jj;
			ms = lmb[i].mulai.mm;
			ds = lmb[i].mulai.dd;
			
			jf = lmb[i].akhir.jj;
			mf = lmb[i].akhir.mm;
			df = lmb[i].akhir.dd;
			
			jb = lmb[i].selisih.jj;
			mb = lmb[i].selisih.mm;
			db = lmb[i].selisih.dd;
			
			strcpy(nm, lmb[i].peserta.nama);
			
			printf("%2d. %-15s  %02d:%02d:%02d  %02d:%02d:%02d  %02d:%02d:%02d\n"
					,i+1, nm, js, ms, ds, jf, mf, df, jb, mb, db);
		}
		printf("==================================================\n");
		printf("Tekan Enter...");
		getch();
	}
}
