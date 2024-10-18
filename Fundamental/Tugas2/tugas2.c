#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main(){
    int angkaTebakan, tebakan, kesempatan, mainLagi;
    char pilihan;

    srand(time(0));

    do{
        angkaTebakan = rand() % 100 + 1;
        kesempatan = 5;
        printf("Selamat datang di permainan Tebak Angka!\n");
        printf("Saya telah memilih sebuah angka dari 1 sampai 100.\n");
        printf("Anda memiliki 5 kesempatan untuk menebak.\n");

        while (kesempatan > 0){
            printf("\nMasukkan tebakan anda: ");
            scanf("%d", &tebakan);

            if(tebakan > angkaTebakan){
                printf("Tebakan anda terlalu tinggi!");
            }else if(tebakan < angkaTebakan){
                printf("Tebakan anda terlalu rendah!");
            }else{
                printf("Selamat! anda menebak dengan benar!\n");
                break;
            }
            kesempatan--;
            printf("Kesempatan tersisa: %d\n", kesempatan);
        }
        if(kesempatan == 0){
            printf("Maaf, anda kehabisan kesempatan. Angka yang benar adalah %d.\n", angkaTebakan);
        }
        printf("Apakah anda ingin bermain lagi? (y/n): ");
        scanf("%c", &pilihan);

        switch (pilihan){
        case 'y':
        case 'Y':
            mainLagi = 1;
            break;
        case 'n':
        case 'N':
            mainLagi = 0;
            printf("Terima Kasih sudah bermain!\n");
            break;
        default:
            printf("Pilihan tidak valid, keluar dari permainan.\n");
            mainLagi = 0;
            break;
        }
    }while (mainLagi);
    return 0;
}