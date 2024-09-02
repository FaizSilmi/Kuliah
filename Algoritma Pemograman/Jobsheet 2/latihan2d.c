/*  
	Nama File      : latihan2c.c 
	Programmer     : Muhammad Faiz Silmi (24343099)
	Tgl. pembuatan : 02 September 2024 
	Deskripsi      : program ini melakukan konversi suhu dari celcius
*/


#include <stdio.h> 
int main() {
	printf("Project jobsheet 2 D \n");
	printf("===================== \n");
	printf("Progammer : Muhammad Faiz Silmi A \n");
	printf("NIM       : 24343099 \n");
	printf("===================== \n");
	float celsius, fahrenheit, reumur, kelvin; 
	// Masukkan celcius
	printf("Masukkan suhu dalam Celsius: "); 
	scanf("%f", &celsius); 
	// Konversi
	fahrenheit = (9.0 / 5.0) * celsius + 32;
	reumur = (4.0 / 5.0) * celsius;
	kelvin = celsius + 273;
	// Hasil
	printf("Fahrenheit= %.2f \n", fahrenheit);
	printf("Reumur= %.2f \n", reumur);
	printf("Kelvin= %.2f \n", kelvin);
	return 0;
}

