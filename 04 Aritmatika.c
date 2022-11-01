#include <stdio.h>

int main() {
	int a = 7;
	int b = 4;
	
	int penjumlahan = a + b;
	int pengurangan = a - b;
	int pembagian = a / b;
	int perkalian = a * b;
	int modulus = a % b;
	
	printf("Penjumlahan\n");
	printf("%d + %d = %d", a, b, penjumlahan);
	
	printf("\nPengurangan\n");
	printf("%d - %d = %d", a, b, pengurangan);
	
	printf("\nPembagian\n");
	printf("%d / %d = %d", a, b, pembagian);
	
	printf("\nPerkalian\n");
	printf("%d * %d = %d", a, b, perkalian);
	
	printf("\nModulus\n");	
	printf("%d %% %d = %d", a, b, modulus);
	
	return 0;
}