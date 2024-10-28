#include <stdio.h>

#define MAX_PESERTA 100

void inputDataPeserta(int *jumlahPeserta, char namaPeserta[MAX_PESERTA][20]){

    printf("Masukkan jumlah peserta: ");
    scanf("%d", jumlahPeserta);

    int hasil[MAX_PESERTA][20];
    int total[MAX_PESERTA];
    
    for(int i = 0; i < *jumlahPeserta; i++){
    printf("Masukkan nama peserta ke %d: ", i + 1);
    scanf("%s", namaPeserta[i]);

    printf("Peserta %s:\n", namaPeserta[i]);

        for (int k = 0; k < 5; k++) {
            printf("Hasil percobaan %d: ", k + 1);
            scanf("%d", &hasil[i][k]);
            total[i] += hasil[i][k];
        }
    }

    printf("\nHasil akhir pertandingan memanah:\n");
    for (int i = 0; i < *jumlahPeserta; i++) {
        printf("Peserta %s - Total Skor: %d\n", namaPeserta[i], total[i]);
    }

  }

void scoreData(){   
    printf("List score: ");
}
void informasiData(){
    printf("Nama Peserta: \n");
    printf("");
}
int main() {
    int pilihan;
    int jumlahPeserta;
    char namaPeserta[MAX_PESERTA][20];
    printf("Piluh menu: \n");
    printf("1. Input Data Peserta: \n");
    printf("2. Score data peserta: \n");
    printf("3. Ranking data peserta: \n");
    printf("4. Keluar\n");
    printf("Masukkan pilihan: ");
    scanf("%d", &pilihan);

    switch (pilihan)
    {
    case 1:
        inputDataPeserta(&jumlahPeserta, namaPeserta);
        break;
    
    default:
        break;
    }

    return 0;
}
