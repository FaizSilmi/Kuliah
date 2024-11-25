/*
	Nama File: struct5.c
	Menggunakan array of struct dan fungsi yg mengembalikan var struct
	
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3

typedef struct{
	char nama[30];
	char nim[5];
	double ipk;
} MHS;

//deklarasi fungsi2
//fungsi untuk mengisi data struct dan mengembalikan var struct
MHS isiData(char *nm, char *ni, double ip);
//fungsi mengcetak info data pd struct
void infoData(MHS mhsKu[]);

int main(){
	MHS myMhs[N];
	int i;
	char namanya[30], nimnya[5];
	double ipknya;
	
	printf("Mengisi data struct:\n");
	for(i=0;i<N;i++){
		printf("Data Mahasiswa ke-%d\n", i+1);
		printf("Ketikkan nama mahasiswa: ");
		gets(namanya); fflush(stdin);
		printf("Ketikkan NIM Mahasiswa: ");
		gets(nimnya); fflush(stdin);
		printf("Ketikkan IPK Mahasiswa: ");
		scanf("%lf",&ipknya); fflush(stdin);
	
		//panggil fungsi mengisi data pada struct
		myMhs[i] = isiData(namanya, nimnya, ipknya);	
	}
	
	
	//panggil fungsi untuk mencetak info mahsiswa
	infoData(myMhs);
	return 0;
}

//definisi fungsi]
//fungsi untuk mengisi data struct dan mengemabilan var struct
MHS isiData(char *nm, char *ni, double ip){
	MHS *mhs = (MHS *)malloc(sizeof(MHS));
	strcpy(mhs->nama, nm);
	strcpy(mhs->nim, ni);
	mhs->ipk = ip;
	
	return *mhs;
}

//fungsi mengcetak info data pd struct
void infoData(MHS mhsKu[]){
	int i;
	printf("Informasi Mahasiswa\n");
	for(i=0;i<N;i++){
		printf("Mahasis ke-%d\n", i+1);
		printf("Nama Mahasiswa : %s\n",mhsKu[i].nama);
		printf("NIM Mahasiswa  : %s\n",mhsKu[i].nim);
		printf("IPK Mahasiswa  : %0.2lf\n",mhsKu[i].ipk);	
	}
	
}