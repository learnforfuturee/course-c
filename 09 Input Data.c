#include <stdio.h>

int main() {
	int angka;
	float desimal;
	char chr;
	char str[15];
	
	printf("Masukkan Angka : ");
	scanf("%d", &angka);
	
	printf("Masukkan Angka Desimal : ");
	scanf("%f", &desimal);
	
	printf("Masukkan Char : ");
	scanf("%c", &chr);
	
	printf("Masukkan String : ");
	scanf("%[^\n]s", str); // With Space
	scanf("%s", str); // No Space
	
	printf("%d, %f, %c, %s", angka, desimal, chr, str);
	
	return 0;
}