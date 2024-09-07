/*  
	Nama File      : Tugas13.c 
	Programmer     : Muhammad Faiz Silmi (24343099)
	Tgl. pembuatan : 07 September 2024 
	Deskripsi      : program ini untuk mencari selisih waktu
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int jaw, maw, daw, totaw;
	int jak, mak, dak, totak;
	int totas, jas, mas, das;
	char ch;
	printf("Project Tugas 13 \n");
	printf("===================== \n");
	printf("Progammer : Muhammad Faiz Silmi \n");
	printf("NIM       : 24343099 \n");
	printf("===================== \n");
	printf("Masukkan waktu awal (ex: 07:30:15)= ");
	scanf("%d%c%d%c%d", &jaw, &ch, &maw, &ch, &daw);
	printf("Ketikkan waktu akhir (ex: 07:30:15): ");
	scanf("%d%c%d%c%d", &jak, &ch, &mak, &ch, &dak);
	// Menghitung
	totaw = jaw * 3600 + maw * 60 + daw;
	totak = jak * 3600 +mak * 60 + dak;
	totas = totak - totaw;
	// Konversi totas
	jas = totas/3600;
	mas = (totas%3600)/60;
	das = (totas%3600)%60;
	// Output
	printf("Waktu Awal   : %d%c%d%c%d\n", jaw, ch, maw, ch, daw);
	printf("Waktu Akhir  : %d%c%d%c%d\n", jak, ch, mak, ch, dak);
	printf("Selisih Waktu: %d%c%d%c%d\n", jas, ch, mas, ch, das);

}
