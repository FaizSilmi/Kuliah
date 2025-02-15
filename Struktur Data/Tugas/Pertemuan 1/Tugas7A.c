#include <stdio.h>

#define MAX 100

void judul();
void tampilkanBarang(int arr[], int size);
void tambahBarang(int arr[], int *size, int capacity, int harga);
void updateBarang(int arr[], int pos, int size, int hargaBaru);
void hapusBarang(int arr[], int *size, int pos);
int cariHargaTertinggi(int arr[], int size);
int cariHargaTerendah(int arr[], int size);

void judul(){
	printf("====================================\n");
    printf("Nama   	      : Muhammad Faiz Silmi\n");
    printf("NIM           : 24343099\n");
    printf("Matakuliah	: Struktur Data\n");
    printf("Nama Program  : Sistem Inventori Barang\n");
    printf("====================================\n\n\n");
}

// Fungsi untuk menampilkan daftar harga barang
void tampilkanBarang(int arr[], int size) {
	int i;
    if (size == 0) {
        printf("Inventori kosong.\n");
        return;
    }
    for (i = 0; i < size; i++) {
        printf("Barang ke-%d: Rp%d\n", i + 1, arr[i]);
    }
}

// Fungsi untuk menambahkan harga barang
void tambahBarang(int arr[], int *size, int capacity, int harga) {
    if (*size < capacity) {
        arr[*size] = harga;
        (*size)++;
        printf("Barang berhasil ditambahkan.\n");
    } else {
        printf("Kapasitas inventori penuh! Tidak dapat menambahkan barang.\n");
    }
}

// Fungsi untuk memperbarui harga barang
void updateBarang(int arr[], int pos, int size, int hargaBaru) {
    if (pos >= 0 && pos < size) {
        arr[pos] = hargaBaru;
        printf("Harga barang ke-%d telah diperbarui menjadi Rp%d.\n", pos + 1, arr[pos]);
    } else {
        printf("Posisi tidak valid!\n");
    }
}

// Fungsi untuk menghapus data barang
void hapusBarang(int arr[], int *size, int pos) {
	int i;
    if (pos >= 0 && pos < *size) {
        for (i = pos; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*size)--;
        printf("Barang ke-%d berhasil dihapus.\n", pos + 1);
    } else {
        printf("Posisi tidak valid!\n");
    }
}

// Fungsi untuk mencari harga tertinggi
int cariHargaTertinggi(int arr[], int size) {
    int max = arr[0];
    int i;
    for (i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Fungsi untuk mencari harga terendah
int cariHargaTerendah(int arr[], int size) {
    int min = arr[0];
    int i;
    for (i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int harga[MAX];
    int size = 0, pilihan, hargaBaru, pos;
    judul();

    while (1) {
        printf("\nMenu Sistem Inventori Barang:\n");
        printf("1. Tampilkan Daftar Harga\n");
        printf("2. Tambah Harga Barang Baru\n");
        printf("3. Perbarui Harga Barang\n");
        printf("4. Hapus Data Barang\n");
        printf("5. Cari Harga Tertinggi\n");
        printf("6. Cari Harga Terendah\n");
        printf("7. Keluar\n");
        printf("Pilih operasi: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tampilkanBarang(harga, size);
                break;
            case 2:
                printf("Masukkan harga barang baru: Rp");
                scanf("%d", &hargaBaru);
                tambahBarang(harga, &size, MAX, hargaBaru);
                break;
            case 3:
                printf("Masukkan posisi barang yang ingin diperbarui: ");
                scanf("%d", &pos);
                printf("Masukkan harga baru: Rp");
                scanf("%d", &hargaBaru);
                updateBarang(harga, pos - 1, size, hargaBaru);
                break;
            case 4:
                printf("Masukkan posisi barang yang ingin dihapus: ");
                scanf("%d", &pos);
                hapusBarang(harga, &size, pos - 1);
                break;
            case 5:
                if (size > 0) {
                    printf("Harga tertinggi adalah: Rp%d\n", cariHargaTertinggi(harga, size));
                } else {
                    printf("Inventori kosong.\n");
                }
                break;
            case 6:
                if (size > 0) {
                    printf("Harga terendah adalah: Rp%d\n", cariHargaTerendah(harga, size));
                } else {
                    printf("Inventori kosong.\n");
                }
                break;
            case 7:
                return 0;
            default:
                printf("Pilihan tidak valid!\n");
        }
    }
}

