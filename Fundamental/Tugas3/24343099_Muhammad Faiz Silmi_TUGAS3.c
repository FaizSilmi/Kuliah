#include <stdio.h>
#include<math.h>

void hanoi(int n, char asal, char tujuan, char bantu){
    if(n == 1){
        printf("Pindahkan cakram 1 dari tiang %c ke tiang %c\n", asal, tujuan);
        return;
    }
    hanoi (n - 1, asal, bantu, tujuan);
    printf("Pindahkan cakram %d dari tiang %c ke tiang %c\n", n, asal, tujuan);
}

int main(){
    int cakram, totalLangkah;

    printf("Masukkan jumlah cakram: ");
    scanf("%d", &cakram);

    printf("Langkah-langkah untuk memindahkan %d cakram: \n", cakram);
    hanoi(cakram, 'A', 'C', 'B');

    totalLangkah = pow(2, cakram) - 1;
    printf("Jumlah total langkah yang diperlukan: %d\n", totalLangkah);
    
    return 0;
}