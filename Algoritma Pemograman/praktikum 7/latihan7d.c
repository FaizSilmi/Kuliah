#include <stdio.h>

// Deklarasi fungsi untuk menampilkan nilai variabel melalui pointer ke pointer
void tampilkanNilai(int **ptr);

int main() {
    int nilai = 10;
    int *ptr = &nilai;
    int **pptr = &ptr;

    // Menampilkan nilai variabel melalui pointer ke pointer
    tampilkanNilai(pptr);

    return 0;
}
// Definisi fungsi untuk menampilkan nilai variabel melalui pointer ke pointer
void tampilkanNilai(int **ptr) {
    printf("Nilai variabel: %d\n", **ptr);
}

