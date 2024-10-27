/*
    Nama     : Muhammad Faiz Silmi
    NIM      : 24343099
    File     : 24343099_Muhammad Faiz Silmi_LATIHAN5.1_B.c
*/
#include<stdio.h>

float hitungKelilingLingkaran(float jarijari)
{
    return 2 * 3.14 * jarijari;
}

int main()
{
    printf("======================================\n");
    printf("Nama     : Muhammad Faiz Silmi\n");
    printf("NIM      : 24343099\n");
    printf("======================================\n");
    float jarijari;

    printf("Masukkan jari jari lingkaran: ");
    scanf("%f", &jarijari);

    float keliling = hitungKelilingLingkaran(jarijari);
    printf("Keliling lingkaran adalah: %.2f\n", keliling);

    return 0;
}
