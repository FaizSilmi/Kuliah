#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nama file untuk log
const char *logFileName = "I:\\Kuliah\\Kuliah\\Fundamental\\Project\\log.txt";

// Fungsi untuk menambahkan log ke file
void writeLog(const char *message) {
    FILE *logFile = fopen(logFileName, "a");
    if (logFile == NULL) {
        printf("Gagal membuka file log.\n");
        return;
    }
    fprintf(logFile, "%s\n", message);
    fclose(logFile);
}

// Fungsi untuk membuat file baru
void createFile() {
    char filename[100];
    printf("Masukkan nama file yang ingin dibuat: ");
    getchar(); // Membersihkan buffer
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Menghapus karakter newline

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Gagal membuat file \"%s\".\n", filename);
        char logMessage[150];
        sprintf(logMessage, "buatfile: %s", filename);
        writeLog(logMessage);
    } else {
        printf("File \"%s\" berhasil dibuat.\n", filename);
        char logMessage[150];
        sprintf(logMessage, "buatfile: %s", filename);
        writeLog(logMessage);
        fclose(file);
    }
}

// Fungsi untuk menulis data ke file
void writeFile() {
    char filename[100];
    char content[500];

    printf("Masukkan nama file yang ingin ditulis: ");
    getchar(); // Membersihkan buffer
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Menghapus karakter newline

    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("File \"%s\" tidak ditemukan.\n", filename);
        char logMessage[150];
        sprintf(logMessage, "isifile: %s (Gagal)", filename);
        writeLog(logMessage);
    } else {
        printf("Masukkan isi file: ");
        fgets(content, sizeof(content), stdin);

        fprintf(file, "%s", content);
        printf("Berhasil menulis ke file \"%s\".\n", filename);
        char logMessage[150];
        sprintf(logMessage, "isifile: %s \"%s\"", filename, content);
        writeLog(logMessage);
        fclose(file);
    }
}

// Fungsi untuk membaca dan menampilkan isi file
void readFile() {
    char filename[100];
    char ch;

    printf("Masukkan nama file yang ingin dibaca: ");
    getchar(); // Membersihkan buffer
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Menghapus karakter newline

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File \"%s\" tidak ditemukan.\n", filename);
    } else {
        printf("Isi file \"%s\":\n", filename);
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
        }
        fclose(file);
    }
}

// Fungsi untuk menghapus file
void deleteFile() {
    char filename[100];
    printf("Masukkan nama file yang ingin dihapus: ");
    getchar(); // Membersihkan buffer
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Menghapus karakter newline

    if (remove(filename) == 0) {
        printf("File \"%s\" berhasil dihapus.\n", filename);
        char logMessage[150];
        sprintf(logMessage, "hapusfile: %s", filename);
        writeLog(logMessage);
    } else {
        printf("Gagal menghapus file \"%s\".\n", filename);
        char logMessage[150];
        sprintf(logMessage, "hapusfile: %s (Gagal)", filename);
        writeLog(logMessage);
    }
}

int main() {
    int choice;

    // Log bahwa program dimulai
    writeLog("Program dimulai.");

    while (1) {
        printf("======Sistem Manajemen File Sederhana=======\n");
        printf("Nama\t: Muhammad Faiz Silmi\n");
        printf("NIM\t: 24343099\n");
        printf("============================================\n");
        printf("1. Buat file\n");
        printf("2. Tulis ke file\n");
        printf("3. Baca file\n");
        printf("4. Hapus file\n");
        printf("5. Keluar\n");
        printf("Pilih opsi (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                writeFile();
                break;
            case 3:
                readFile(); // Tidak ada log untuk membaca file
                break;
            case 4:
                deleteFile();
                break;
            case 5:
                printf("Keluar dari program.\n");
                writeLog("Program selesai.");
                exit(0);
            default:
                printf("Opsi tidak valid, coba lagi.\n");
        }
    }

    return 0;
}
