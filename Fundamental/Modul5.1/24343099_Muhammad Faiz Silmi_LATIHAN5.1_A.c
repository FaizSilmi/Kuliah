/*
    Nama           : Muhammad Faiz Silmi
    NIM            : 24343099
    Tgl. Pembuatan :
    File           : 24343099_Muhammad Faiz Silmi_LATIHAN5.1_A.c
*/
#include<stdio.h>

int hitungLuasPersegiPanjang(int panjang, int lebar)
{
    return panjang * lebar;
}

int main()
{
    int panjang, lebar;
    printf("======================================\n");
    printf("Nama     : Muhammad Faiz Silmi\n");
    printf("NIM      : 24343099\n");
    printf("======================================\n");
    printf("Masukkan panjang: ");
    scanf("%d", &panjang);
    printf("Masukkan lebar: ");
    scanf("%d", &lebar);

    int luas = hitungLuasPersegiPanjang(panjang, lebar);
    printf("Luas persegi panjang adalah: %d\n", luas);

    return 0;
}