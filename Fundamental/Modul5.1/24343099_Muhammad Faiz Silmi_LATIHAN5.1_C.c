/*
    Nama           : Muhammad Faiz Silmi
    NIM            : 24343099
    Tgl. Pembuatan :
    File           : 24343099_Muhammad Faiz Silmi_LATIHAN5.1_C.c
*/
#include<stdio.h>

int hitungFaktorial(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    else{
        return n * hitungFaktorial(n - 1);
    }
}

int main()
{
    printf("======================================\n");
    printf("Nama     : Muhammad Faiz Silmi\n");
    printf("NIM      : 24343099\n");
    printf("======================================\n");
    int n;

    printf("Masukkan bilangan bulat positif: ");
    scanf("%d", &n);

    int faktorial = hitungFaktorial(n);
    printf("Faktorial dari %d adalah: %d\n", n, faktorial);

    return 0;
}