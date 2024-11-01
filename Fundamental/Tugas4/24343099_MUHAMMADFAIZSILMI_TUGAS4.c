#include <stdio.h>
#include <string.h>

#define MAX_BUKU 100
#define MAX_STRING 100

struct  Buku
{
  char judul[MAX_STRING];
  char pengarang[MAX_BUKU];
  int tahun;
};

void tambahBuku(struct Buku *perpustakaan, int *jumlahBuku);
void tampilkanBuku(struct  Buku *perpustakaan, int jumlahBuku);
void cariBuku(struct Buku *perpustakaan, int jumlahBuku, char *judulCari);

int main(){
  struct Buku perpustakaan[MAX_BUKU];
  int jumlahBuku = 0;
  int pilihan;
  char judulCari[MAX_STRING];

  do{printf("\n--- Manajemen Buku Perpustakaan ---\n");
    printf("1. Tambah Buku\n");
    printf("2. Tampilkan Semua Buku\n");
    printf("3. Cari Buku Berdasarkan Judul\n");
    printf("4. Keluar\n");  
    printf("Pilihan anda: ");
    scanf("%d", &pilihan);
    getchar();

    switch (pilihan)
    {
    case 1:
      tambahBuku(perpustakaan, &jumlahBuku);
      break;
    case 2:
      tampilkanBuku(perpustakaan, jumlahBuku);
      break;
    case 3:
      printf("Masukkan judul buku yang ingin dicari: ");
      fgets(judulCari, MAX_STRING, stdin);
      judulCari[strcspn(judulCari, "\n")] = 0;
      cariBuku(perpustakaan, jumlahBuku, judulCari);
      break;
    case 4:
      printf("Keluar dari program\n");
      break;
    default:
    printf("Pilihan tidak valid.\n");
      
    }
  }  while (pilihan != 4);
  return 0;
}

void tambahBuku(struct Buku *perpustakaan, int *jumlahBuku)
{
  if (*jumlahBuku < MAX_BUKU){
    printf("Masukkan judul buku: ");
    fgets(perpustakaan[*jumlahBuku].judul, MAX_STRING, stdin);
    perpustakaan[*jumlahBuku].judul[strcspn(perpustakaan[*jumlahBuku].judul, "\n")] = 0;

    printf("Masukkan pengarang buku: ");
    fgets(perpustakaan[*jumlahBuku].pengarang, MAX_STRING, stdin);
    perpustakaan[*jumlahBuku].pengarang[strcspn(perpustakaan[*jumlahBuku]. pengarang, "\n")] = 0;

    printf("Masukkan tahun terbit: ");
    scanf("%d", &perpustakaan[*jumlahBuku].tahun);
    getchar();

    (*jumlahBuku)++;
    printf("Nuku berhasil ditambahkan!\n");
  }else{
    printf("Perpustakaan penuh, tidak bisa menambah buku lagi!\n");
  }
}

void tampilkanBuku(struct Buku *perpustakaan, int jumlahBuku)
{
  if (jumlahBuku == 0){
    printf("Tidak ada buku di perpustakaan,\n");
  }else{
    printf("\n-- Daftar Buku di Perpustakaan --\n");
    for(int i = 0; i < jumlahBuku; i++){
      printf("Buku %d:\n", i + 1);
      printf("Judul     : %s\n", perpustakaan[i].judul);
      printf("Pengarang : %s\n", perpustakaan[i].pengarang);
      printf("Tahun     : %d\n", perpustakaan[i].tahun);
    }
  }
}

void cariBuku(struct Buku *perpustakaan, int jumlahBuku, char *judulCari)
{
  int ditemukan = 0;
  for (int i = 0; i < jumlahBuku; i++){
    if (strcmp(perpustakaan[i].judul, judulCari) == 0){
    printf("\nBuku ditemukan:\n");
    printf("Judul     : %s\n", perpustakaan[i].judul);
    printf("Pengarang : %s\n", perpustakaan[i].pengarang);
    printf("Tahun     : %d\n", perpustakaan[i].tahun);
    ditemukan = 1;
    break;
    }
  }
  if(!ditemukan){
    printf("Buku dengan judul '%s tidak ditemukan.\n", judulCari);
  }
}
