/*
	Nama File: panah1.c
	Pengelolaan Pertandingan Memanah
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3 //banyaknya Peserta

//deklarasi fungsi
void judul();
void selesai();
void entriData();
int hitungSkor(int nilainya);
void info();

//data
char peserta [N][20];
int nilai[N][3];
int skor[N];


int main(){
	judul();
	entriData();
	info();
	selesai();
	return 0;
}

//definisi fungsi
void judul(){
	printf("\nPERTANDINGAN MEMANAH\n");
	printf("============================\n");
	printf("Programmer: Muhammad Faiz Silmi(24343099)\n");
	printf("Tekan Enter....");
	getch();
}

void selesai(){
	printf("\nSelesai....bye... bye...\n");
	printf("Sampai jumpa....tekan tombol...");
	getch();
}

void entriData(){
	int i, j, skornya;
	
	printf("\nEntri Data\n");
	for(i=0;i<N;i++){
		printf("Ketikkan nama peserta ke-%d: ", i+1);
		gets(peserta[i]); fflush(stdin);
		printf("Entrikan no sasaran yg dikenai:");
		skornya=0;
		for(j=0;j<3;j++){
			printf("\nSasaran kesempatan ke-%d: ", j+1);
			scanf("%d", &nilai[i][j]); fflush(stdin);
			skornya += hitungSkor(nilai[i][j]);
		}	
		skor[i] = skornya;
	}
}

int hitungSkor(int nilainya){
	int skornya=0;
	switch(nilainya){
		
		case 1: skornya += 1000;
				break;
		case 2: skornya += 900;
				break;
		case 3: skornya += 800;
				break;
		case 4: skornya += 700;
				break;
		case 5: skornya += 600;
				break;
		case 6: skornya += 500;
				break;
		case 7: skornya += 400;
				break;
		case 8: skornya += 300;
				break;
		case 9: skornya += 200;
				break;
		case 10:skornya += 100;
				break;
		default:skornya += 0;
				break;
	}
	return skornya;
}

void info(){
	int i;
	
	printf("\nDAFTAR HASIL PERTANDINGAN\n");
	printf("====================================================\n");
	printf("NO. NAMA                ke-1   ke-2   ke-3   SKOR\n");
	printf("====================================================\n");
	for(i=0;i<N;i++){
		printf("%2d. %-15s\t%d\t%d\t%d\t%d\n", i+1, peserta[i],
			nilai[i][0], nilai[i][1], nilai[i][2], skor[i]);
	}
	printf("=====================================================\n");
}