#include <stdio.h>

int main() {
	
	/*printf("Learn For Future\n");
	printf("Learn For Future\n");
	printf("Learn For Future\n");
	printf("Learn For Future\n");
	printf("Learn For Future\n");
	printf("Learn For Future\n");
	printf("Learn For Future\n");
	printf("Learn For Future\n");
	printf("Learn For Future\n");
	printf("Learn For Future\n"); */
	
	int i = 0;
	
	for(i = 0;i < 10;i++) {
		printf("Learn For Future\n");
	}
	
	// Kelipatan 2 dari 0 sampai 10
	for(i = 0;i <= 10;i = i + 2) { // bisa juga pakai i+=2
		printf("%d ", i);
	}
	printf("\n");
	
	i = 0;
	while(i < 10) {
		printf("%d. Learn For Future\n", i);
		
		i++;
	}
	
	i = 0;
	do {
		printf("%d. Learn For Future\n", i);
		i++;
	} while(i < 10);
	
	return 0;
}