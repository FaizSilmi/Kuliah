#include<stdio.h>
#include<math.h>
#define PHI 3.14

int main(){
	float d, k, t, p, l;
	// Masukkan variabel
	printf("Masukkan kedalaman= ");
	scanf("%f", &k);
	printf("Masukkan diameter= ");
	scanf("%f", &d);
	printf("Masukkan lebar= ");
	scanf("%f", &l);
	printf("Masukkan panjang= ");
	scanf("%f", &p);
	// Proses
	t = (PHI * ((d/2) * (d/2)) * k)/(l*p);
	// Hasil
	printf("Ketinggian tanah= %.2f", t);
}
