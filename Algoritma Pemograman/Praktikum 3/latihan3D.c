/* 	Nama File		: latihan3D.c
	Programmer		: tuliskan nama dan nim anda
	Tgl. pembuatan		: 10 September 2024
	Deskripsi		: program ini melakukan perhitungan diskon	                            
*/

#include <stdio.h>

int main() {
    double harga, diskon, total;

    // Meminta pengguna memasukkan harga dan persentase diskon
    printf("Harga barang: ");
    scanf("%lf", &harga);

    printf("Persentase diskon (dalam persen): ");
    scanf("%lf", &diskon);

    // Menghitung total harga setelah diskon
    total = harga * (1 - diskon / 100.0);

    // Menyimpan detail pembelian ke dalam berkas "nota.txt" menggunakan fprintf
    FILE *file = fopen("nota.txt", "w");
    if (file != NULL) {
        fprintf(file, "Harga Barang			: Rp. %.2lf\n", harga);
        fprintf(file, "Persentase Diskon			: Rp. %.2lf%%\n", diskon);
        fprintf(file, "Total Harga Setelah Diskon	: Rp. %.2lf\n", total);
        fclose(file);
        printf("Detail pembelian telah disimpan ke dalam berkas 'nota.txt'.\n");
    } else {
        printf("Gagal membuka berkas untuk penyimpanan detail pembelian.\n");
        return 1; // Keluar dengan kode kesalahan
    }

    return 0; // Keluar program
}

