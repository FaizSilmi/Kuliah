#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipe fungsi
void createFile();
void writeFile();
void readFile();
void deleteFile();
void processFile(const char *inputFilename, const char *outputFilename);
void viewFileList();  // Menambahkan fungsi untuk melihat daftar file
void removeFileFromLog(const char *filename);  // Menambahkan fungsi untuk menghapus file dari log

// Fungsi untuk menulis log ke file output
void logToFile(FILE *outputFile, const char *message) {
    fprintf(outputFile, "%s\n", message);
}

// Fungsi untuk menambahkan nama file ke file log
void logCreatedFile(const char *filename) {
    FILE *logFile = fopen("file_log.txt", "a");
    if (logFile != NULL) {
        fprintf(logFile, "%s\n", filename);
        fclose(logFile);
    } else {
        printf("Gagal membuka file log untuk mencatat nama file.\n");
    }
}

// Fungsi untuk menghapus file dari log
void removeFileFromLog(const char *filename) {
    FILE *logFile = fopen("file_log.txt", "r");
    FILE *tempFile = fopen("temp_log.txt", "w");
    if (logFile == NULL || tempFile == NULL) {
        printf("Gagal membuka file log untuk menghapus file.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), logFile)) {
        line[strcspn(line, "\n")] = '\0';  // Menghapus newline
        if (strcmp(line, filename) != 0) {
            fprintf(tempFile, "%s\n", line);
        }
    }

    fclose(logFile);
    fclose(tempFile);
    
    // Menggantikan file log dengan file sementara yang baru
    remove("file_log.txt");
    rename("temp_log.txt", "file_log.txt");
}

// Fungsi untuk memproses perintah dari file input dan mencatat hasil ke file output
void processFile(const char *inputFilename, const char *outputFilename) {
    FILE *inputFile = fopen(inputFilename, "r");
    FILE *outputFile = fopen(outputFilename, "w");

    if (inputFile == NULL) {
        printf("Gagal membuka file input \"%s\".\n", inputFilename);
        return;
    }
    if (outputFile == NULL) {
        printf("Gagal membuka file output \"%s\".\n", outputFilename);
        fclose(inputFile);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), inputFile)) {
        line[strcspn(line, "\n")] = '\0'; // Menghapus newline

        // Memproses perintah berdasarkan isi baris
        if (strncmp(line, "buatfile:", 9) == 0) {
            char filename[100];
            sscanf(line + 9, "%s", filename);
            FILE *newFile = fopen(filename, "w");
            if (newFile) {
                fclose(newFile);
                char logMessage[200];
                snprintf(logMessage, sizeof(logMessage), "File %s dibuat.", filename);
                logToFile(outputFile, logMessage);
                logCreatedFile(filename);  // Mencatat file yang dibuat
            } else {
                printf("Gagal membuat file %s.\n", filename);
            }
        } else if (strncmp(line, "isifile:", 8) == 0) {
            char filename[100], content[200];
            sscanf(line + 8, "%s %[^\n]", filename, content);
            FILE *file = fopen(filename, "a");
            if (file) {
                fprintf(file, "%s\n", content);
                fclose(file);
                char logMessage[200];
                snprintf(logMessage, sizeof(logMessage), "File %s diisi dengan: %s", filename, content);
                logToFile(outputFile, logMessage);
            } else {
                printf("Gagal membuka file %s.\n", filename);
            }
        } else if (strncmp(line, "hapusfile:", 10) == 0) {
            char filename[100];
            sscanf(line + 10, "%s", filename);
            if (remove(filename) == 0) {
                char logMessage[200];
                snprintf(logMessage, sizeof(logMessage), "File %s dihapus.", filename);
                logToFile(outputFile, logMessage);
                removeFileFromLog(filename);  // Menghapus nama file dari log
            } else {
                printf("Gagal menghapus file %s.\n", filename);
            }
        }
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("Proses selesai. Hasil dicatat di file \"%s\".\n", outputFilename);
}

// Fungsi untuk melihat daftar file yang telah dibuat
void viewFileList() {
    FILE *logFile = fopen("file_log.txt", "r");
    if (logFile == NULL) {
        printf("Tidak ada file yang tercatat.\n");
        return;
    }

    char filename[100];
    printf("Daftar file yang telah dibuat:\n");
    while (fgets(filename, sizeof(filename), logFile)) {
        filename[strcspn(filename, "\n")] = '\0';  // Menghapus newline
        printf("%s\n", filename);
    }

    fclose(logFile);
}

// Fungsi utama
int main() {
    int choice;

    while (1) {
        printf("====== Sistem Manajemen File Sederhana ======\n");
        printf("1. Buat file\n");
        printf("2. Tulis ke file\n");
        printf("3. Baca file\n");
        printf("4. Hapus file\n");
        printf("5. Proses file (dari input.txt ke output.txt)\n");
        printf("6. Lihat daftar file yang dibuat\n");
        printf("7. Keluar\n");
        printf("Pilih opsi (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                writeFile();
                break;
            case 3:
                readFile();
                break;
            case 4:
                deleteFile();
                break;
            case 5:
                processFile("input.txt", "output.txt");
                break;
            case 6:
                viewFileList();  // Menampilkan daftar file
                break;
            case 7:
                printf("Keluar dari program.\n");
                exit(0);
            default:
                printf("Opsi tidak valid, coba lagi.\n");
        }
    }

    return 0;
}

// Fungsi untuk membuat file baru
void createFile() {
    char filename[100];
    printf("Masukkan nama file yang ingin dibuat: ");
    getchar(); // Membersihkan buffer
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Menghapus karakter newline

    FILE *file = fopen(filename, "w");
    if (file) {
        printf("File \"%s\" berhasil dibuat.\n", filename);
        fclose(file);
        logCreatedFile(filename);  // Mencatat file yang dibuat
    } else {
        printf("Gagal membuat file \"%s\".\n", filename);
    }
}

// Fungsi untuk menulis ke file
void writeFile() {
    char filename[100], content[500];
    printf("Masukkan nama file yang ingin ditulis: ");
    getchar(); // Membersihkan buffer
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Menghapus karakter newline

    FILE *file = fopen(filename, "a");
    if (file) {
        printf("Masukkan isi file: ");
        fgets(content, sizeof(content), stdin);
        fprintf(file, "%s", content);
        fclose(file);
        printf("Berhasil menulis ke file \"%s\".\n", filename);
    } else {
        printf("Gagal membuka file \"%s\".\n", filename);
    }
}

// Fungsi untuk membaca isi file
void readFile() {
    char filename[100];
    printf("Masukkan nama file yang ingin dibaca: ");
    getchar(); // Membersihkan buffer
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    FILE *file = fopen(filename, "r");
    if (file) {
        char ch;
        printf("Isi file \"%s\":\n", filename);
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
        }
        fclose(file);
    } else {
        printf("File \"%s\" tidak ditemukan.\n", filename);
    }
}

// Fungsi untuk menghapus file
void deleteFile() {
    char filename[100];
    printf("Masukkan nama file yang ingin dihapus: ");
    getchar(); // Membersihkan buffer
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    if (remove(filename) == 0) {
        printf("File \"%s\" berhasil dihapus.\n", filename);
        removeFileFromLog(filename);  // Menghapus nama file dari log
    } else {
        printf("Gagal menghapus file \"%s\".\n", filename);
    }
}
