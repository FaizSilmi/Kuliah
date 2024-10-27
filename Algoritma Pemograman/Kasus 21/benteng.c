#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 2 // Jumlah peserta

// Deklarasi fungsi
void judul();
void selesai();
void entriData();
double hitungVolume(double panjang, double lebar, double tinggi);
void info();

// Data peserta
char peserta[N][20];
double panjang[N];
double lebar[N];
double tinggi[N];
double volume[N];

int main(){
    judul();
    entriData();
    info();
    selesai();
    return 0;
}

void judul(){
    printf("\nPERTANDINGAN MEMBANGUN BENTENG\n");
    printf("==============================\n");
    printf("Programmer: Anu\n");
    printf("Tekan Enter untuk melanjutkan...");
    getchar();
}

void selesai(){
    printf("\nSelesai... Terima kasih sudah menggunakan program ini!\n");
}

void entriData(){
    int i;
    
    printf("\nEntri Data\n");
    for(i = 0; i < N; i++){
        printf("Ketikkan nama peserta ke-%d: ", i+1);
        gets(peserta[i]); fflush(stdin);
        
        printf("Ketikkan panjang benteng untuk %s (meter): ", peserta[i]);
        scanf("%lf", &panjang[i]); fflush(stdin);
        
        printf("Ketikkan lebar benteng untuk %s (meter): ", peserta[i]);
        scanf("%lf", &lebar[i]); fflush(stdin);
        
        printf("Ketikkan tinggi benteng untuk %s (meter): ", peserta[i]);
        scanf("%lf", &tinggi[i]); fflush(stdin);
        
        // Hitung volume benteng
        volume[i] = hitungVolume(panjang[i], lebar[i], tinggi[i]);
    }
}

double hitungVolume(double panjang, double lebar, double tinggi){
    return panjang * lebar * tinggi;
}

void info(){
    int i;
    
    printf("\nDAFTAR HASIL PERTANDINGAN BENTENG\n");
    printf("-----------------------------------------------------------\n");
    printf("NO. PESERTA        PANJANG  LEBAR  TINGGI  VOLUME (m³)\n");
    printf("-----------------------------------------------------------\n");
    for(i = 0; i < N; i++){
        printf("%2d. %-15s  %.2lf    %.2lf    %.2lf    %.2lf\n", 
               i+1, peserta[i], panjang[i], lebar[i], tinggi[i], volume[i]);
    }
    printf("-----------------------------------------------------------\n");
}
