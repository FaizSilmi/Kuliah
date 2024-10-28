#include <stdio.h>

// Deklarasi fungsi untuk menukar nilai dua variabel menggunakan pointer
void tukar(int *a, int *b);

int main() {
    int x = 10, y = 20;

    // Menampilkan nilai sebelum ditukar
    printf("Sebelum ditukar: x = %d, y = %d\n", x, y);

    // Menukar nilai dua variabel
    tukar(&x, &y);

    // Menampilkan nilai setelah ditukar
    printf("Setelah ditukar: x = %d, y = %d\n", x, y);
    //printf("Alamat: x = %p, y = %p\n", &x,&y);


    return 0;
}

// Definisi fungsi untuk menukar nilai dua variabel menggunakan pointer
void tukar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

