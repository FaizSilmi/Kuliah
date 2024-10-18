#include <stdio.h>
#include <string.h>

int main(){
    int jumlahPerulangan;
    int i;
    printf("Masukkan jumlah data mahasiswa: ");
    scanf("%d", &jumlahPerulangan);

    for(int i = 0; i < jumlahPerulangan; i++)
    {
        char nama[100];
        char nim[20];
        char prodi[50];
        char universitas[50];
        char alamat[100];

        printf("Sistem informasi data mahasiswa\n");

        printf("Masukkan nama: \n");
        scanf("%s", &nama);

        printf("Masukkan NIM: \n");
        scanf("%s", &nim);

        printf("Masukkan prodi studi: \n");
        scanf("%s", &prodi);

        printf("Masukkan universitas: \n");
        scanf("%s", &universitas);

        printf("Masukkan alamat: \n");
        scanf("%s", &alamat);

        printf("\nInformasi data mahasiswa yang dimasukan:\n");
        printf("Nama: %s\n", nama);
        printf("NIM: %s\n", nim);
        printf("Program Studi: %s\n", prodi);
        printf("universitas: %s\n", universitas);
        printf("Alamat: %s\n", alamat);

        puts("\nTerima kasih atas informasi yang anda berikan!");
    }
    return 0;
}