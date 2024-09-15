#include<stdio.h>

int main(){
	char name[50];
	int  noidentitas, nilai;
	
	// Masukkan data siswa
	printf("Masukkan nama siswa: ");
	gets(name);
	printf("Masukkan Nomor Identitas: ");
	scanf("%d", &noidentitas);
	printf("Masukkan nilai: ");
	scanf("%d", &nilai);
	// Menampilkan di file .txt
	FILE *file = fopen("data_siswa.txt", "w");
    if (file != NULL) {
        fprintf(file, "Nama Siswa: %s\n", name);
        fprintf(file, "Nomor Identitas: %d\n", noidentitas);
        fprintf(file, "Nilai: %d\n", nilai);
        fclose(file);
        printf("Data siswa telah disimpan ke dalam berkas 'data_siswa.txt'.\n");
    } else {
        printf("Gagal membuka berkas untuk penyimpanan detail data siswa.\n");
        return 1; // Keluar dengan kode kesalahan
    }
}
