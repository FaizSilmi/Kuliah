/* 	Nama File		: latihan5C.c
	Programmer		: Muhammad Faiz Silmi 24343099
	Tgl. pembuatan	: 07/10/2024
	Deskripsi		: program ini melakukan perhitungan luas dan keliling 
                                                  segitiga	                            
*/

#include <stdio.h>

//deklarasi fungsi
void judul(); 
void input();

//deklarasi variabel sisi segitiga
int sisi1, sisi2, sisi3;

//definisi fungsi
void judul(){
	printf ("\t\t\n Program ini Menghitung Luas Segitiga");
	printf ("\t\t\n Programmer : TIM IT 1F");
	printf ("\t\t\n Dibuat : 4 Oktober 2023");
	printf ("\t\t\n ====================================\n");
}

void input(){
	printf("Nilai Sisi 1: ");
	scanf("%d", &sisi1);
	printf("Nilai Sisi 2: ");
	scanf("%d", &sisi2);
	printf("Nilai Sisi 3: ");
	scanf("%d", &sisi3);
}

int kell(int kll){
	kll = sisi1+sisi2+sisi3;
	printf ("===========================\n");
	printf  ("Keliling Segitiga : %d cm \n", kll);
	return kll;	
}

float luas(float s){
	s = (sisi1 + sisi2 + sisi3) / 2;
    printf  ("Luas Segitiga : %.2f cm2", s);
   	printf ("\n===========================\n");
	return sqrt(s * (s - sisi1) * (s - sisi2) * (s - sisi3));
    
}

void cek(){
	if (sisi1 == sisi2 && sisi2 == sisi3) {
        printf("Segitiga ini adalah segitiga sama sisi.\n");
    } else if (sisi1 == sisi2 || sisi2 == sisi3 || sisi1 == sisi3) {
        printf("Segitiga ini adalah segitiga sama kaki.\n");
    } else {
        printf("Segitiga ini adalah segitiga sembarang.\n");
    }
}

main(){
	judul();
	input();
	
	int keliling;
	kell(keliling);
	
	float l;
	luas(l);
	
	cek(sisi1, sisi2, sisi3);
}
