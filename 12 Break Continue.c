#include <stdio.h>

int main() {
	
	int i = 0;
	
	for (i = 0; i < 10; i++) {
		if (i % 2 == 1) {
			continue;
		} else if (i == 7) {
			break;
		}
		printf("%d. Learn For Future\n", i);
	}
	
	do {
		printf("Menu\n");
		printf("1. Login\n");
		printf("2. Register\n");
		printf("3. Out\n");
		
		printf("Pilih Menu : ");
		scanf("%d", &i);
		
		if (i == 1) {
			printf("Login Menu\n");
		} else if (i == 2) {
			printf("Register Menu\n");
		} else if (i == 3) {
			printf("Out\n");
			break;
		}
		
	} while (i < 99999);
	
	return 0;
}