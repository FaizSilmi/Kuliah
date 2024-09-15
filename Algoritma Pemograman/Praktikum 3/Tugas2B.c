#include <stdio.h>

int main() {
    char kalimat[1000]; // Buffer untuk menyimpan kalimat

    // Meminta pengguna untuk memasukkan sebuah kalimat
    printf("Masukkan sebuah kalimat: ");
    fgets(kalimat, sizeof(kalimat), stdin);

    // Menghitung panjang kalimat
    int panjang = 0;
    while (kalimat[panjang] != '\0') {  //Memastikan bahwa loop terus berjalan hingga akhir loop
        if (kalimat[panjang] != '\n') { // Tidak menghitung karakter newline
            panjang++;  // Menghitung jumlah karakter pada kalimat
        } else {
            break;
        }
    }

    // Menampilkan jumlah karakter
    printf("Jumlah karakter dalam kalimat: %d\n", panjang);

    return 0;
}

