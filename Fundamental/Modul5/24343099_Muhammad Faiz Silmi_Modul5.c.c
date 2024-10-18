#include <stdio.h>
#include <string.h>

int main() {
    int jumlahPerulangan;
    printf("Masukkan jumlah data mahasiswa: ");
    scanf("%d", &jumlahPerulangan);
    getchar(); 

    for (int i = 0; i < jumlahPerulangan; i++) {
        char nama[100];
        char nim[20];
        char prodi[50];
        char universitas[50];
        char alamat[100];

        printf("Sistem informasi data mahasiswa\n");

        printf("Masukkan nama: \n");
        fgets(nama, sizeof(nama), stdin);
        nama[strcspn(nama, "\n")] = 0;

        printf("Masukkan NIM: \n");
        fgets(nim, sizeof(nim), stdin);
        nim[strcspn(nim, "\n")] = 0;

        printf("Masukkan prodi studi: \n");
        fgets(prodi, sizeof(prodi), stdin);
        prodi[strcspn(prodi, "\n")] = 0;

        printf("Masukkan universitas: \n");
        fgets(universitas, sizeof(universitas), stdin);
        universitas[strcspn(universitas, "\n")] = 0;

        printf("Masukkan alamat: \n");
        fgets(alamat, sizeof(alamat), stdin);
        alamat[strcspn(alamat, "\n")] = 0;

        printf("\nInformasi data mahasiswa yang dimasukan:\n");
        printf("Nama: %s\n", nama);
        printf("NIM: %s\n", nim);
        printf("Program Studi: %s\n", prodi);
        printf("Universitas: %s\n", universitas);
        printf("Alamat: %s\n", alamat);

        puts("\nTerima kasih atas informasi yang anda berikan!");
    }
    return 0;
}
