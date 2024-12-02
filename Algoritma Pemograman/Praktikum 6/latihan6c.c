/* 	
    Nama File		: latihan6C.c
	Programmer		: Muhammad Faiz Silmi 24343099
	Tgl. pembuatan	: 14/10/2024
	Deskripsi		: program ini melakukan operasi matriks	                            
*/

#include <stdio.h>
int i,j,k;

// Fungsi untuk menampilkan matriks
void displayMatrix(int mat[], int rows, int cols) {
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", mat[i * cols + j]);
        }
        printf("\n");
    }
}

// Fungsi untuk mengganti ordo matriks
void changeMatrixOrder(int mat[], int* rows, int* cols) {
    printf("Masukkan ordo matriks yang baru (baris kolom): ");
    scanf("%d %d", rows, cols);
    printf("Ordo matriks telah diganti menjadi %d x %d.\n", *rows, *cols);
}

// Fungsi untuk mengisi matriks
void fillMatrix(int mat[], int rows, int cols) {
    printf("Masukkan elemen-elemen matriks %dx%d:\n", rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &mat[i * cols + j]);
        }
    }
}

// Fungsi untuk menambahkan dua matriks
void addMatrix(int mat1[], int mat2[], int result[], int rows, int cols) {
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i * cols + j] = mat1[i * cols + j] + mat2[i * cols + j];
        }
    }
}

// Fungsi untuk mengurangkan dua matriks
void subtractMatrix(int mat1[], int mat2[], int result[], int rows, int cols) {
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i * cols + j] = mat1[i * cols + j] - mat2[i * cols + j];
        }
    }
}

// Fungsi untuk mengalikan dua matriks
void multiplyMatrix(int mat1[], int mat2[], int result[], int rows1, int cols1, int cols2) {
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            result[i * cols2 + j] = 0;
            for (k = 0; k < cols1; k++) {
                result[i * cols2 + j] += mat1[i * cols1 + k] * mat2[k * cols2 + j];
            }
        }
    }
}

int main() {
    int rows, cols;
    printf("\nMasukkan ordo matriks (baris kolom): ");
    scanf("%d %d", &rows, &cols);

    char matrixName[20];
    printf("\nMasukkan nama matriks: ");
    scanf("%s", matrixName);

    int matrix[rows][cols];

    // Mengisi matriks
    fillMatrix(matrix[0], rows, cols);

    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Tampilkan Matriks\n");
        printf("2. Ganti Ordo Matriks\n");
        printf("3. Ganti Isi Matriks\n");
        printf("4. Penjumlahan Matriks\n");
        printf("5. Pengurangan Matriks\n");
        printf("6. Perkalian Matriks\n");
        printf("7. Keluar\n");

        printf("Pilih menu: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("%s Matriks:\n", matrixName);
            displayMatrix(matrix[0], rows, cols);
        } else if (choice == 2) {
            changeMatrixOrder(matrix[0], &rows, &cols);
        } else if (choice == 3) {
            fillMatrix(matrix[0], rows, cols);
        } else if (choice == 4) {
            int matrix2[rows][cols];
            printf("Masukkan matriks kedua untuk penjumlahan:\n");
            fillMatrix(matrix2[0], rows, cols);
            int result[rows][cols];
            addMatrix(matrix[0], matrix2[0], result[0], rows, cols);
            printf("Hasil penjumlahan matriks:\n");
            displayMatrix(result[0], rows, cols);
        } else if (choice == 5) {
            int matrix2[rows][cols];
            printf("Masukkan matriks kedua untuk pengurangan:\n");
            fillMatrix(matrix2[0], rows, cols);
            int result[rows][cols];
            subtractMatrix(matrix[0], matrix2[0], result[0], rows, cols);
            printf("Hasil pengurangan matriks:\n");
            displayMatrix(result[0], rows, cols);
        } else if (choice == 6) {
            int cols2;
            printf("Masukkan ordo matriks kedua (baris kolom): ");
            scanf("%d %d", &rows, &cols2);
            if (cols != rows) {
                printf("Operasi perkalian matriks tidak valid.\n");
            } else {
                int matrix2[cols][cols2];
                printf("Masukkan matriks kedua untuk perkalian:\n");
                fillMatrix(matrix2[0], cols, cols2);
                int result[rows][cols2];
                multiplyMatrix(matrix[0], matrix2[0], result[0], rows, cols, cols2);
                printf("Hasil perkalian matriks:\n");
                displayMatrix(result[0], rows, cols2);
            }
        } else if (choice == 7) {
            break;
        } else {
            printf("Menu tidak valid. Pilih menu yang benar.\n");
        }
    }

    return 0;
}
