#include <stdio.h>

int main() {
	
	
	int aritmatik;
	float angka1, angka2, hasil;
	awal:
	printf("Masukkan angka pertama : ");
	scanf("%f", &angka1);
	
	printf("Masukkan angka kedua : ");
	scanf("%f", &angka2);
	
	printf("Pilih Operator\n");
	printf("1. Penjumlahan\n");
	printf("2. Pengurangan\n");		
	printf("3. Perkalian\n");
	printf("4. Pembagian\n");
	printf("5. Finish\n");
	printf("Pilih Operasi : ");
	scanf("%d", &aritmatik);
	
	switch (aritmatik) {
		case 1: hasil = angka1 + angka2; break;
		case 2: hasil = angka1 - angka2; break;
		case 3: hasil = angka1 * angka2; break;				
		case 4: hasil = angka1 / angka2; break;
		case 5: goto finish;
	}
	
	printf("Hasil = %.2f\n\n", hasil);
	
	goto awal;
	finish:
	
	return 0;
}