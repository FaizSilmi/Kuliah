#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 2 // Jumlah grup

// Deklarasi fungsi
void judul();
void selesai();
void entriData();
int hitungWaktuTempuh(int t_start, int t_finish);
int hitungWaktuTotal(int waktuPelari[4]);
void ekstrakWaktu(int wk);
void info();

// Data peserta
char grup[N][20];
int waktuStart[N][4]; // Waktu start masing-masing pelari dalam grup
int waktuFinish[N][4]; // Waktu finish masing-masing pelari dalam grup
int waktuTempuh[N][4]; // Waktu tempuh masing-masing pelari
int waktuTotal[N]; // Akumulasi waktu total untuk setiap grup

int main(){
    judul();
    entriData();
    info();
    selesai();
    return 0;
}

void judul(){
    printf("\nLOMBA LARI ESTAFET 4 x 100 METER\n");
    printf("================================\n");
    printf("Programmer: Anu\n");
    printf("Tekan Enter untuk melanjutkan...");
    getchar();
}

void selesai(){
    printf("\nSelesai... Terima kasih sudah menggunakan program ini!\n");
}

void entriData(){
    int i, j, mm1, ss1, ms1, mm2, ss2, ms2;
    
    printf("\nEntri Data\n");
    for(i = 0; i < N; i++){
        printf("Ketikkan nama grup ke-%d: ", i+1);
        gets(grup[i]); fflush(stdin);
        
        // Input waktu start dan waktu finish masing-masing pelari dalam grup
        for(j = 0; j < 4; j++){
            printf("Ketikkan waktu start pelari ke-%d dalam grup %s (menit:detik:milidetik, contoh 00:12:35): ", j+1, grup[i]);
            scanf("%d:%d:%d", &mm1, &ss1, &ms1);
            waktuStart[i][j] = mm1 * 60000 + ss1 * 1000 + ms1; // Konversi menjadi milidetik
            
            printf("Ketikkan waktu finish pelari ke-%d dalam grup %s (menit:detik:milidetik, contoh 00:12:35): ", j+1, grup[i]);
            scanf("%d:%d:%d", &mm2, &ss2, &ms2);
            waktuFinish[i][j] = mm2 * 60000 + ss2 * 1000 + ms2; // Konversi menjadi milidetik
            
            // Hitung waktu tempuh pelari
            waktuTempuh[i][j] = hitungWaktuTempuh(waktuStart[i][j], waktuFinish[i][j]);
        }
        
        // Hitung akumulasi waktu total grup
        waktuTotal[i] = hitungWaktuTotal(waktuTempuh[i]);
    }
}

int hitungWaktuTempuh(int t_start, int t_finish){
    return t_finish - t_start;
}

int hitungWaktuTotal(int waktuPelari[4]){
    int total = 0, i;
    for(i = 0; i < 4; i++){
        total += waktuPelari[i];
    }
    return total;
}

void ekstrakWaktu(int wk){
    int mm, ss, ms;
    mm = wk / 60000;
    ss = (wk % 60000) / 1000;
    ms = wk % 1000;
    printf("%02d:%02d.%02d", mm, ss, ms);
}

void info(){
    int i, j;
    
    printf("\nDAFTAR HASIL LOMBA LARI ESTAFET 4x100 METER\n");
    printf("--------------------------------------------------------------------\n");
    printf("NO. GRUP        PELARI 1   PELARI 2   PELARI 3   PELARI 4   WAKTU TOTAL\n");
    printf("--------------------------------------------------------------------\n");
    for(i = 0; i < N; i++){
        printf("%2d. %-12s", i+1, grup[i]);
        for(j = 0; j < 4; j++){
            printf("   ");
            ekstrakWaktu(waktuTempuh[i][j]);
        }
        printf("   ");
        ekstrakWaktu(waktuTotal[i]);
        printf("\n");
    }
    printf("--------------------------------------------------------------------\n");
}
