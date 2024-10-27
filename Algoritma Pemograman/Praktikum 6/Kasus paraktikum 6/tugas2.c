#include<stdio.h>
#include<string.h>

// Variabel global untuk menyimpan tanggal, bulan, dan zodiak
int bulan, tanggal;
char zodiak[20];  // Menggunakan array untuk menyimpan string

// Fungsi judul untuk menampilkan identitas program dan programmer
void judul(){
    printf("==============================\n");
    printf("Nama    : Muhammad Faiz Silmi\n");
    printf("NIM     : 24343099\n");
    printf("Program : Ramalan Zodiak\n");
    printf("==============================\n");
}

// Fungsi bacaKelahiran untuk membaca input tanggal dan bulan lahir
void bacaKelahiran(){
    printf("Masukkan tanggal dan bulan lahir (TT BB): ");
    scanf("%d %d", &tanggal, &bulan);
}

// Fungsi tentukanZodiak untuk menentukan zodiak berdasarkan tanggal dan bulan
void tentukanZodiak(int tanggal, int bulan){
    if ((bulan == 1 && tanggal >= 20) || (bulan == 2 && tanggal <= 18)) {
        strcpy(zodiak, "Aquarius");
    } else if ((bulan == 2 && tanggal >= 19) || (bulan == 3 && tanggal <= 20)) {
        strcpy(zodiak, "Pisces");
    } else if ((bulan == 3 && tanggal >= 21) || (bulan == 4 && tanggal <= 19)) {
        strcpy(zodiak, "Aries");
    } else if ((bulan == 4 && tanggal >= 20) || (bulan == 5 && tanggal <= 20)) {
        strcpy(zodiak, "Taurus");
    } else if ((bulan == 5 && tanggal >= 21) || (bulan == 6 && tanggal <= 20)) {
        strcpy(zodiak, "Gemini");
    } else if ((bulan == 6 && tanggal >= 21) || (bulan == 7 && tanggal <= 22)) {
        strcpy(zodiak, "Cancer");
    } else if ((bulan == 7 && tanggal >= 23) || (bulan == 8 && tanggal <= 22)) {
        strcpy(zodiak, "Leo");
    } else if ((bulan == 8 && tanggal >= 23) || (bulan == 9 && tanggal <= 22)) {
        strcpy(zodiak, "Virgo");
    } else if ((bulan == 9 && tanggal >= 23) || (bulan == 10 && tanggal <= 22)) {
        strcpy(zodiak, "Libra");
    } else if ((bulan == 10 && tanggal >= 23) || (bulan == 11 && tanggal <= 21)) {
        strcpy(zodiak, "Scorpio");
    } else if ((bulan == 11 && tanggal >= 22) || (bulan == 12 && tanggal <= 21)) {
        strcpy(zodiak, "Sagittarius");
    } else if ((bulan == 12 && tanggal >= 22) || (bulan == 1 && tanggal <= 19)) {
        strcpy(zodiak, "Capricorn");
    } else {
        strcpy(zodiak, "Zodiak tidak valid");
    }
}

// Fungsi tampilkanRamalan untuk menampilkan ramalan berdasarkan zodiak
void tampilkanRamalan(char zodiak[]){
    printf("Zodiak Anda adalah: %s\n", zodiak);
    printf("Ramalan hari ini untuk %s:\n", zodiak);

    if (strcmp(zodiak, "Aquarius") == 0) {
        printf("Hari ini adalah hari yang baik untuk berpikir kreatif dan berbagi ide.\n");
    } else if (strcmp(zodiak, "Pisces") == 0) {
        printf("Anda mungkin merasa sangat intuitif hari ini. Percayalah pada insting Anda.\n");
    } else if (strcmp(zodiak, "Aries") == 0) {
        printf("Energi Anda tinggi hari ini, gunakan kesempatan ini untuk memulai sesuatu yang baru.\n");
    } else if (strcmp(zodiak, "Taurus") == 0) {
        printf("Kesabaran dan stabilitas Anda akan diuji, tetapi Anda akan melewatinya dengan tenang.\n");
    } else if (strcmp(zodiak, "Gemini") == 0) {
        printf("Komunikasi adalah kunci hari ini. Jadilah terbuka dalam menyampaikan ide-ide Anda.\n");
    } else if (strcmp(zodiak, "Cancer") == 0) {
        printf("Hari ini fokuslah pada keluarga dan emosi Anda. Jaga orang-orang terdekat Anda.\n");
    } else if (strcmp(zodiak, "Leo") == 0) {
        printf("Percaya diri dan ambisi Anda akan membawa Anda pada kesuksesan hari ini.\n");
    } else if (strcmp(zodiak, "Virgo") == 0) {
        printf("Perhatian Anda terhadap detail akan sangat berguna hari ini. Tetap fokus.\n");
    } else if (strcmp(zodiak, "Libra") == 0) {
        printf("Hari ini adalah waktu yang baik untuk mencari keseimbangan dalam kehidupan pribadi dan profesional.\n");
    } else if (strcmp(zodiak, "Scorpio") == 0) {
        printf("Anda mungkin menemukan diri Anda lebih intens dan penuh semangat hari ini. Gunakan energi itu dengan bijak.\n");
    } else if (strcmp(zodiak, "Sagittarius") == 0) {
        printf("Hari ini adalah waktu yang baik untuk eksplorasi dan petualangan baru.\n");
    } else if (strcmp(zodiak, "Capricorn") == 0) {
        printf("Fokuslah pada tujuan jangka panjang Anda hari ini. Kerja keras Anda akan terbayar.\n");
    } else {
        printf("Maaf, tidak ada ramalan untuk zodiak ini.\n");
    }
}

int main(){
    // Memanggil fungsi judul
    judul();

    // Memanggil fungsi bacaKelahiran untuk mengambil input tanggal dan bulan
    bacaKelahiran();

    // Memanggil fungsi tentukanZodiak untuk menentukan zodiak
    tentukanZodiak(tanggal, bulan);

    // Memanggil fungsi tampilkanRamalan untuk menampilkan ramalan
    tampilkanRamalan(zodiak);

    return 0;
}
