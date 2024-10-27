/*
	Nama File: marathon.c
	Pengelolaan Perlombaan Maraton
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define N 2 //banyak peserta
#define JRK 1000.0 //jarak dalam meter

//deklarasi fungsi
void judul();
void selesai();
void entriData();
int hitungSelisihWaktu(int t1, int t2);
double hitungKecepatan(int waktu);
void ekstrakWaktu(int wk);
void info();

//data
char peserta [N][20];
int start[N];
int finish[N];
double kecepatan[N];


int main(){
	judul();
	entriData();
	info();
	return 0;
}

//definisi fungsi
void judul(){
	printf("\nPERTANDINGAN MARATON\n");
	printf("============================\n");
	printf("Programmer: Muhammad Faiz Silmi (24343099)\n");
	printf("Tekan Enter....");
	getch();
}

void selesai(){
	int waktu;
	
	printf("\nSelesai....bye... bye...\n");
	printf("Sampai jumpa....tekan tombol...");
	getch();
}

void entriData(){
	int i, jj, mm, dd, waktu;
	char h;
	
	printf("\nEntri Data\n");
	//Waktu strat sama untuk semua peserta
	printf("Ketikkan waktu Start (ex, 07:30:00): ");
	scanf("%d%c%d%c%d", &jj, &h, &mm, &h, &dd); fflush(stdin);
	//printf("%2d:%2d:%2d\n",jj, mm, dd); getch();
	//waktu start sama untuk semua peserta
	for(i=0;i<N;i++){
		start[i] = jj*3600 + mm*60 + dd;
	}
	//nama2 peserta
	for(i=0;i<N;i++){
		printf("Ketikkan nama peserta ke-%d: ", i+1);
		gets(peserta[i]); fflush(stdin);
		printf("Entrikan Waktu Finish (ex, 10:30:15): ");
		scanf("%d%c%d%c%d", &jj, &h, &mm, &h, &dd); fflush(stdin);
		finish[i] = jj*3600 + mm*60 + dd;
		//hitung selisih waktu
		waktu = hitungSelisihWaktu(finish[i], start[i]);
		//hirung kecepatan dan simpan di array
		kecepatan[i] = hitungKecepatan(waktu);
	}
}

int hitungSelisihWaktu(int tf, int ts){
	int selisih;
	
	selisih = tf - ts;
	return selisih;
}

double hitungKecepatan(int wk){
	double kec;
	
	kec = JRK/(double)wk;
	
	return kec;
}

void ekstrakWaktu(int wk){
	int j, m, d;
	
	j = wk/3600;
	m = wk%3600/60;
	d = wk%3600%60;
	
	printf("%02d:%02d:%02d", j, m, d);
}

void info(){
	int i,js, ms, ds;
	int jf, mf, df;
	int jb, mb, db;
	
	printf("\nDAFTAR HASIL PERLOMBAAN\n");
	printf("---------------------------------------------------------\n");
	printf("NO. PESERTA         START     FINISH    SELISIH   KEC\n");
	printf("---------------------------------------------------------\n");
	for(i=0;i<N;i++){
		printf("%2d. %-15s ", i+1, peserta[i]);
		ekstrakWaktu(start[i]);
		printf("  ");
		ekstrakWaktu(finish[i]);
		printf("  ");
		ekstrakWaktu(finish[i] - start[i]);
		printf("  ");
		printf("%0.2lf m/dt\n", kecepatan[i]);
	}
	printf("---------------------------------------------------------\n");
}