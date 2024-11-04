/*
	Nama File: struct3.c
	Menggunakan typedef dan pointer struct 
	
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nama[30];
	char nim[5];
	double ipk;
} MHS;

//deklarasi fungsi2
//fungsi untuk mengisi data struct
void isiData(MHS *mhsKu, char *nm, char *ni, double ip);
//fungsi mengcetak info data pd struct
void infoData(MHS *mhsKu);

int main(){
	MHS myMhs;
	char namanya[30], nimnya[5];
	double ipknya;
	
	
	printf("Mengisi data struct:\n");
	printf("Ketikkan nama mahasiswa: ");
	gets(namanya); fflush(stdin);
	printf("Ketikkan NIM Mahasiswa: ");
	gets(nimnya); fflush(stdin);
	printf("Ketikkan IPK Mahasiswa: ");
	scanf("%lf",&ipknya); fflush(stdin);
	
	//panggil fungsi mengisi data pada struct
	isiData(&myMhs, namanya, nimnya, ipknya);
	
	//panggil fungsi untuk mencetak info mahsiswa
	infoData(&myMhs);
	return 0;
}

//definisi fungsi]
//fungsi untuk mengisi data struct
void isiData(MHS *mhsKu, char *nm, char *ni, double ip){
	strcpy(mhsKu->nama, nm);
	strcpy(mhsKu->nim, ni);
	mhsKu->ipk = ip;
}

//fungsi mengcetak info data pd struct
void infoData(MHS *mhsKu){
	printf("Informasi Mahasiswa\n");
	printf("Nama Mahasiswa : %s\n",mhsKu->nama);
	printf("NIM Mahasiswa  : %s\n",mhsKu->nim);
	printf("IPK Mahasiswa  : %0.2lf\n",mhsKu->ipk);
}