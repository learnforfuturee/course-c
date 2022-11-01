#include <stdio.h>
#include <stdbool.h>

int main() {
	int angka = 1234;
	float decimal = 30.4;
	double decimalPanjang = 30.1;
	char karakter = 'A';
	char str[100] = "Ini adalah String";
	int array[5] = {1,2,3,4,5};
	bool boolean = false;
	
	printf("%d\n", angka);
	printf("%.2f\n", decimal);
	printf("%.2lf\n", decimalPanjang);
	printf("%c\n", karakter);
	printf("%s\n", str);
	printf("%d\n", array[4]);
	printf("%d\n", boolean);
					
	return 0;
}