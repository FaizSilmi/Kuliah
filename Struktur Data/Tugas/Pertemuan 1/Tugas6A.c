#include <stdio.h>

#define MAX 100

void judul();
void tampilkanNilai(int arr[], int size);
void tambahNilai(int arr[], int *size, int capacity, int nilai);
void updateNilai(int arr[], int pos, int size, int nilaiBaru);
void hapusNilai(int arr[], int *size, int pos);

void tampilkanNilai(int arr[], int size) {
	int i;
    for (i = 0; i < size; i++) {
        printf("Siswa ke-%d: %d\n", i + 1, arr[i]);
    }
}

void tambahNilai(int arr[], int *size, int capacity, int nilai) {
    if (*size < capacity) {
        arr[*size] = nilai;
        (*size)++;
    } else {
        printf("Kapasitas penuh! Tidak dapat menambahkan nilai.\n");
    }
}

void updateNilai(int arr[], int pos, int size, int nilaiBaru) {
    if (pos >= 0 && pos < size) {
        arr[pos] = nilaiBaru;
    } else {
        printf("Posisi tidak valid!\n");
    }
}

void hapusNilai(int arr[], int *size, int pos) {
	int i;
    if (pos >= 0 && pos < *size) {
        for (i = pos; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*size)--;
    } else {
        printf("Posisi tidak valid!\n");
    }
}

void judul(){
	printf("====================================\n");
    printf("Nama   	      : Muhammad Faiz Silmi\n");
    printf("NIM           : 24343099\n");
    printf("Matakuliah	: Struktur Data\n");
    printf("Nama Program  : Pengelolaan Nilai Siswa\n");
    printf("====================================\n\n\n");
}

int main() {
	judul();
    int nilai[MAX];
    int size = 0, pilihan, nilaiBaru, pos;

    while (1) {
        printf("\nMenu Pengelolaan Nilai Siswa:\n");
        printf("1. Tampilkan Nilai\n");
        printf("2. Tambah Nilai\n");
        printf("3. Update Nilai\n");
        printf("4. Hapus Nilai\n");
        printf("5. Keluar\n");
        printf("Pilih operasi: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tampilkanNilai(nilai, size);
                break;
            case 2:
                printf("Masukkan nilai siswa baru: ");
                scanf("%d", &nilaiBaru);
                tambahNilai(nilai, &size, MAX, nilaiBaru);
                break;
            case 3:
                printf("Masukkan posisi nilai yang ingin diupdate: ");
                scanf("%d", &pos);
                printf("Masukkan nilai baru: ");
                scanf("%d", &nilaiBaru);
                updateNilai(nilai, pos - 1, size, nilaiBaru);
                break;
            case 4:
                printf("Masukkan posisi nilai yang ingin dihapus: ");
                scanf("%d", &pos);
                hapusNilai(nilai, &size, pos - 1);
                break;
            case 5:
                return 0;
            default:
                printf("Pilihan tidak valid!\n");
        }
    }
}

