#include <stdio.h>

// Deklarasi fungsi untuk menampilkan nilai variabel melalui pointer
void tampilkanNilai(int *ptr);

int main() {
    int nilai = 10;
    int *ptr = &nilai;

    // Menampilkan nilai variabel melalui pointer
    tampilkanNilai(ptr);

    return 0;
}

// Definisi fungsi untuk menampilkan nilai variabel melalui pointer
void tampilkanNilai(int *ptr) {
    printf("Nilai variabel: %d\n", *ptr);
}
