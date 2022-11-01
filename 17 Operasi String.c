#include <stdio.h>
#include <string.h>

int main() {
	char string1[] = "learn for future";
	char string2[] = "learn";
	char string3[20];
	
	// Copy
	char copy[20];
	strcpy(copy, string1);
	printf("%s\n\n", copy);
	
	// Perbandingan
	int a = strcmp(string1, string2); // hasil negatif positif tunjukkan
	printf("%d", a);
	
	// Panjang
	char cekPanjang[20];
	scanf("%[^\n]s", cekPanjang); // error in ketika input space
	printf("Panjang String adalah %d\n\n", strlen(cekPanjang));
	
	// Menggabungkan
	strcat(string1, " adalah course edutech");
	printf("%s\n", string1);
	
	// mengambil Karakter
	char *inde = strchr(string2, 'F');
	printf("%s", inde);
	
	return 0;
}