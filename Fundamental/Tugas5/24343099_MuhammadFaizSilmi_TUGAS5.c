#include <stdio.h>
#include <stdlib.h>
#include<string.h>

// Definisi struct untuk menyimpan informasi pesanan
struct Pesanan
{
  char namaMakanan[50];
  int jumlah;
  float harga;
  struct Pesanan *next;
};

// Fungsi untuk menambah pesanan
struct Pesanan* tambahPesanan(struct Pesanan *head)
{
  struct Pesanan *newPesanan = (struct Pesanan*) malloc(sizeof(struct Pesanan));
  if (newPesanan == NULL){
    printf("Memori Tidak Cukup!\n");
    return head;
  }

  // Input pesanan dari pengguna
  printf("Masukkan nama makanan: ");
  fgets(newPesanan->namaMakanan, 50, stdin);
  newPesanan->namaMakanan[strcspn(newPesanan->namaMakanan, "\n")] = 0;
  printf("Masukkan jumlah: ");
  scanf("%d", &newPesanan->jumlah);
  printf("Masukkan harga per unit: ");
  scanf("%f", &newPesanan->harga);
  getchar();

  // Mengatur pointer ke pesanan berikutnya
  newPesanan->next = head;
  printf("Pesanan berhasil ditambahkan!\n");
  return newPesanan;
};

// Fungsi untuk menampilkan daftar pesanan
void tampilkanPesanan(struct Pesanan *head){
  struct Pesanan *current = head;
  if (current == NULL){
    printf("Tidak ada pesanan.\n");
    return;
  }

  printf("\n--- Daftar Pesanan ---\n");
  while (current != NULL)
  {
  printf("Nama Makanan: %s\n", current->namaMakanan);
  printf("Jumlah: %d\n", current->jumlah);
  printf("Harga: %.2f\n", current->harga);
  printf("------------------------\n");
  current = current->next;
  }
}

// Fungsi untuk menghapus pesanan
struct Pesanan* hapusPesanan(struct Pesanan *head, char *namaMakanan){
  struct Pesanan *current = head;
  struct Pesanan *prev = NULL;

  while (current != NULL && strcmp(current->namaMakanan, namaMakanan) != 0){
    prev = current;
    current = current->next;
  }
  if (current == NULL){
    printf("Pesanan tidak ditemukan,\n");
    return head;
  }

  //Menghapus pesanan
  if (prev == NULL){
    head = current->next;
  }else{
    prev->next = current->next;
  }
  free(current); //Mengembalikan memor
  printf("Pesanan '%s' telah dihapus.\n", namaMakanan);

  return head;
}

//Fungsi untuk menghitung total pendapatan
void hitungTotalPendapatan(struct Pesanan *head){
  struct Pesanan *current = head;
  float totalPendapatan = 0;

  while (current != NULL){
    totalPendapatan += current->jumlah * current->harga;
    current = current->next;
  }

  printf("Total Pendapatan: %.2f\n", totalPendapatan);
}

// Fungsi untuk mengubah pesanan
struct Pesanan* ubahPesanan(struct Pesanan *head, char *namaMakanan) {
    struct Pesanan *current = head;
    int pilihan;
    
    // Mencari pesanan berdasarkan nama makanan
    while (current != NULL && strcmp(current->namaMakanan, namaMakanan) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Pesanan dengan nama '%s' tidak ditemukan.\n", namaMakanan);
        return head;
    }

    // Menampilkan informasi pesanan yang akan diubah
    printf("\n--- Pesanan yang akan diubah ---\n");
    printf("Nama Makanan: %s\n", current->namaMakanan);
    printf("Jumlah: %d\n", current->jumlah);
    printf("Harga per unit: %.2f\n", current->harga);
    printf("-------------------------------\n");

    // Menampilkan menu pilihan untuk mengubah pesanan
    printf("Apa yang ingin diubah?\n");
    printf("1. Ubah Jumlah\n");
    printf("2. Ubah Harga\n");
    printf("3. Kembali ke menu utama\n");
    printf("Pilihan Anda: ");
    scanf("%d", &pilihan);
    getchar();

    switch (pilihan) {
        case 1:
            printf("Masukkan jumlah baru: ");
            scanf("%d", &current->jumlah);
            printf("Jumlah berhasil diubah!\n");
            break;
        case 2:
            printf("Masukkan harga baru per unit: ");
            scanf("%f", &current->harga);
            printf("Harga berhasil diubah!\n");
            break;
        case 3:
            break;
        default:
            printf("Pilihan tidak valid!\n");
            break;
    }

    return head;
}


int main(){
  struct Pesanan *pesananList = NULL;
  int pilihan;
  char namaMakanan[50];

  do{
    //Menu utama
    printf("\n--- Sistem Manajemen Pesanan Restoran ---\n");
    printf("1. Tambah Pesanan\n");
    printf("2. Tampilkan Semua Pesanan\n");
    printf("3. Hapus Pesanan\n");
    printf("4. Hitung Total Pendapatan\n");
    printf("5. Ubah Pesanan\n");
    printf("6. Keluar\n");
    printf("Pilihan anda: ");
    scanf("%d", &pilihan);
    getchar();

    switch (pilihan)
    {
    case 1:
      pesananList = tambahPesanan(pesananList);
      break;
    case 2:
      tampilkanPesanan(pesananList);
      break;
    case 3:
      printf("Masukkan nama makanan yang akan dihapus: ");
      fgets(namaMakanan, 50, stdin);
      namaMakanan[strcspn(namaMakanan, "\n")] = '\0';
      pesananList = hapusPesanan(pesananList, namaMakanan);
      break;
    case 4:
      hitungTotalPendapatan(pesananList);
      break;
    case 5:
      printf("Masukkan nama makanan yang ingin diubah: ");
      fgets(namaMakanan, 50, stdin);
      namaMakanan[strcspn(namaMakanan, "\n")] = '\0';
      pesananList = ubahPesanan(pesananList, namaMakanan);
      break;
    case 6:
      printf("Keluar dari program.\n");
      break;
    default:
      printf("Pilihan tidak valid!.");
    }
  }while(pilihan != 6);

  // Menghapus semua pesanan dan membebaskan memori sebelum keluar
  while (pesananList != NULL){
    struct Pesamam *temp = pesananList;
    pesananList = pesananList->next;
    free(temp);
  }
  return 0;
}