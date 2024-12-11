#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Deklarasi fungsi
void logToFile(FILE *outputFile, const char *message);
void logCreatedFile(const char *filename);
void removeFileFromLog(const char *filename);
void processFile(const char *inputFilename, const char *outputFilename);
void viewFileList();
void createFile();
void writeFile();
void readFile();
void deleteFile();

// Fungsi untuk mencatat log ke file
void logToFile(FILE *outputFile, const char *message) {
    fprintf(outputFile, "%s\n", message);
}

// Fungsi untuk mencatat nama file yang dibuat
void logCreatedFile(const char *filename) {
    FILE *logFile = fopen("file_log.txt", "a");
    if (logFile) {
        fprintf(logFile, "%s\n", filename);
        fclose(logFile);
    }
}

// Fungsi untuk menghapus nama file dari log
void removeFileFromLog(const char *filename) {
    FILE *logFile = fopen("file_log.txt", "r");
    if (logFile == NULL) {
        return;
    }

    FILE *tempFile = fopen("file_log_temp.txt", "w");
    if (tempFile == NULL) {
        fclose(logFile);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), logFile)) {
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, filename) != 0) {
            fprintf(tempFile, "%s\n", line);
        }
    }

    fclose(logFile);
    fclose(tempFile);

    remove("file_log.txt");
    rename("file_log_temp.txt", "file_log.txt");
}

void processFile(const char *inputFilename, const char *outputFilename) {
    clock_t start_time, end_time;
    start_time = clock(); // Mencatat waktu mulai

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
            if (sscanf(line + 8, "%s \"%[^\"]\"", filename, content) == 2) {
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
            } else {
                printf("Format isifile tidak valid: %s\n", line);
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

    end_time = clock(); // Mencatat waktu selesai
    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Proses selesai dalam waktu %.2f detik. Hasil dicatat di file \"%s\".\n", duration, outputFilename);
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
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {   // Fungsi ini berguna untuk mendeteksi direktori awal
         printf("File akan disimpan di direktori: %s\n", cwd);
    } else {
        perror("getcwd() error");
        return 1;
    }
    const char *newDirectory = "J:\\Kuliah\\Fundamental\\Project\\output"; //Fungsi ini berguna untuk mengubah file direktori
    if (chdir(newDirectory) == 0) {
    printf("Direktori kerja berhasil diubah ke: %s\n", newDirectory);
    } else {
        perror("Gagal mengubah direktori kerja");
    }
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
                viewFileList();
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
