/*
	Nama File: struct.c
	Mendefinisikan dan mendeklarasikan variabel struct
	
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MHS{
	char nama[30];
	char nim[5];
	double ipk;
};
//deklarasi variabel struct
struct MHS mhs1;

//deklarasi fungsi2
//fungsi untuk mengisi data struct
void isiData(char nm[], char ni[], double ip);
//fungsi mengcetak info data pd struct
void infoData(struct MHS mhs);

int main(){
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
	isiData(namanya, nimnya, ipknya);
	
	//panggil fungsi untuk mencetak info mahsiswa
	infoData(mhs1);
	return 0;
}

//definisi fungsi]
//fungsi untuk mengisi data struct
void isiData(char nm[], char ni[], double ip){
	strcpy(mhs1.nama, nm);
	strcpy(mhs1.nim, ni);
	mhs1.ipk = ip;
}

//fungsi mengcetak info data pd struct
void infoData(struct MHS mhs){
	printf("Informasi Mahasiswa\n");
	printf("Nama Mahasiswa : %s\n",mhs.nama);
	printf("NIM Mahasiswa  : %s\n",mhs.nim);
	printf("IPK Mahasiswa  : %0.2lf\n",mhs.ipk);
}