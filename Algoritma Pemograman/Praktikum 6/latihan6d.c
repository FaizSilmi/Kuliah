/* 	Nama File		: latihan6D.c
	Programmer	    : Muhammad Faiz Silmi 24343099
	Tgl. pembuatan	: 14/10/2024
	Deskripsi		: pengelolaan data buku perpustakaan	                            
*/

#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100 // Maksimum buku yang dapat disimpan
#define MAX_STRING_LENGTH 100 // Panjang maksimum string



int main() {
    char titles[MAX_BOOKS][MAX_STRING_LENGTH];
    char authors[MAX_BOOKS][MAX_STRING_LENGTH];
    int years[MAX_BOOKS];
    char classifications[MAX_BOOKS][MAX_STRING_LENGTH];
    int bookCount = 0;
    printf(" pengelolaan data buku perpustakaan	  \n");
    printf("=============================\n");
    printf("Nama : Muhammad Faiz Silmi\n");
    printf("Nim  : 24343099\n");
    printf("=============================\n");
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Tambah Buku\n");
        printf("2. Tampilkan Daftar Buku\n");
        printf("3. Keluar\n");
        printf("Pilih tindakan (1/2/3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (bookCount < MAX_BOOKS) {
                    printf("Masukkan judul buku: ");
                    scanf(" %[^\n]s", titles[bookCount]);
                    printf("Masukkan nama pengarang: ");
                    scanf(" %[^\n]s", authors[bookCount]);
                    printf("Masukkan tahun terbit: ");
                    scanf("%d", &years[bookCount]);
                    printf("Masukkan nomor klasifikasi: ");
                    scanf(" %[^\n]s", classifications[bookCount]);
                    bookCount++;
                } else {
                    printf("Batas jumlah buku telah tercapai. Tidak bisa menambahkan lebih banyak buku.\n");
                }
                break;
            case 2:
                printf("Daftar Buku di Perpustakaan:\n");
                int i;
                for (i = 0; i < bookCount; i++) {
                    printf("Buku %d:\n", i + 1);
                    printf("Judul: %s\n", titles[i]);
                    printf("Pengarang: %s\n", authors[i]);
                    printf("Tahun Terbit: %d\n", years[i]);
                    printf("Nomor Klasifikasi: %s\n", classifications[i]);
                }
                break;
            case 3:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Coba lagi.\n");
        }
    } while (choice != 3);

    return 0;
}
