/*
	Nama File: struct1.c
	Mendefinisikan dan menggunakan variabel struct lokal
	
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MHS{
	char nama[30];
	char nim[5];
	double ipk;
};

//deklarasi fungsi2
//fungsi untuk mengisi data struct
void isiData(struct MHS *mhsKu, char nm[], char ni[], double ip);
//fungsi mengcetak info data pd struct
void infoData(struct MHS *mhsKu);

int main(){
	struct MHS myMhs;
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
void isiData(struct MHS *mhsKu, char nm[], char ni[], double ip){
	strcpy(mhsKu->nama, nm);
	strcpy(mhsKu->nim, ni);
	mhsKu->ipk = ip;
}

//fungsi mengcetak info data pd struct
void infoData(struct MHS *mhsKu){
	printf("Informasi Mahasiswa\n");
	printf("Nama Mahasiswa : %s\n",mhsKu->nama);
	printf("NIM Mahasiswa  : %s\n",mhsKu->nim);
	printf("IPK Mahasiswa  : %0.2lf\n",mhsKu->ipk);
}