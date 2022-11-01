#include <stdio.h>

int main() {
	int a = 8;
	int b = 8;
	int c = 5;
	
	if(a == b) {
		printf("Angka sama");
	}
	
	if(a != b) {
		printf("Angka Tidak Sama");
	}
	
	if(a > c) {
		printf("%d Lebih Besar daripada %d", a, c);
	}
	
	if(a < c) {
		printf("%d Lebih Kecil daripada %d", a, c);
	}
	
	if(a >= c) {
		printf("%d Lebih Besar Samadengan %d", a, c);
	}
	
	if(a <= c) {
		printf("%d Lebih Kecil Samadengan %d", a, c);
	}
	
	return 0;
}