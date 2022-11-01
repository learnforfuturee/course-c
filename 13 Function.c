#include <stdio.h>

void print(char str[]);

int perkalian(int a, int b) {
	int c = a * b;
	return c;
}

int pangkat(int angka, int pangkat) {
	int i, hasil = 1;
	
	for (i = 0; i < pangkat;i ++) {
		hasil = hasil * angka;
	}
	return hasil;
	
}



int main() {
	
	print("Halloooo");
	
	int hasil = pangkat(5, 2);
	
	printf("%d", hasil);
	
	return 0;
}

void print(char str[]) {
	printf("%s\n", str);
}