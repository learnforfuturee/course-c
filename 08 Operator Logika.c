#include <stdio.h>
#include <stdbool.h>

int main() {
	int a = 7;
	int b = 5;
	int c = 10;
	bool d = false;
	
	
	if(a > b && b < c) {
		printf("Ini merupakan contoh Operasi Logika &&\n");
	}
	
	if(a > b || b == c) {
		printf("Ini merupakan contoh operasi Logika ||\n");
	}
	
	if(!d) {
		printf("Ini merupakan contoh dari operator logika not\n");
	}
	
	return 0;
}