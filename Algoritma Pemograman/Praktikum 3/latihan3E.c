/* 	Nama File		: latihan3E.c
	Programmer		: Muhammad Faiz Silmi
	Tgl. pembuatan	: 10 September 2024
	Deskripsi		: program ini melakukan perhitungan cicilan kredit barang	                            
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100]; // Buffer untuk menyimpan input
    char output[100]; // Buffer untuk menyimpan output

    double harga, hutang, bunga, cicilan, uangMuka, sisa, pokok;
    int bulan, kaliKe;

    // Input tanpa format menggunakan fgets()
    printf("Masukkan harga barang		: ");
    fgets(input, sizeof(input), stdin);
    harga = atof(input); // Mengubah teks menjadi double

    printf("Masukkan besar uang muka	: ");
    fgets(input, sizeof(input), stdin);
    uangMuka = atof(input); // Mengubah teks menjadi double

    printf("Masukkan jumlah bulan kredit	: ");
    fgets(input, sizeof(input), stdin);
    bulan = atoi(input); // Mengubah teks menjadi integer

    printf("Masukkan Cicilan kali ke berapa	: ");
    fgets(input, sizeof(input), stdin);
    kaliKe = atoi(input); // Mengubah teks menjadi integer

    // Menghitung pokok hutang
    hutang = harga - uangMuka;

    // Menghitung bunga perbulan
    bunga = (0.09 * hutang) / 12;

    // Menghitung pokok bulanan
    pokok = hutang / bulan;

    // Menghitung besar cicilan perbulan
    cicilan = pokok + bunga;

    // Menghitung sisa hutang
    sisa = hutang - pokok * kaliKe;

    // Menampilkan informasi tanpa pemformatan menggunakan puts()
    puts("\nHarga Barang	: Rp.");
    puts(input);
    puts("Uang Muka: Rp.");
    puts(input);
    printf("Banyaknya bulan cicilan		: %d kali cicilan\n", bulan);
    puts("Pokok Hutang: Rp.");
    puts(input);
    printf("Besar bunga bulanan		: Rp. %.2f\n", bunga);
    puts("Besar Cicilan per bulan		: Rp.");
    puts(input);
    printf("Cicilan ke-: %d\n", kaliKe);
    puts("Sisa Pokok Hutang			: Rp.");
    puts(input);

    return 0;
}

