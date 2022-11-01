#include <stdio.h>

void create();
void read();
void write();

char text[100];

int main() {
	create();
	// write();
	read();
	return 0;
}

void create() {
	FILE *createFile = fopen("file.txt", "a");
	
	fprintf(createFile, "1. Halo ini adalah untuk menulis dalam file\n");
	fprintf(createFile, "2. Halo ini adalah untuk menulis dalam file\n");
	
	fclose(createFile);
}
	
void read() {
	FILE *readFile = fopen("file.txt", "r");
	
	while(fscanf(readFile, "%[^@]\n", text) != EOF) {
		printf("%s\n", text);	
	}
	
	fclose(readFile);
}

void write() {
	FILE *writeFile = fopen("file.txt", "w");
	
	fprintf(writeFile, "1. Halo ini adalah untuk menulis dalam file\n");
	fprintf(writeFile, "2. Halo ini adalah untuk menulis dalam file\n");

	
	fclose(writeFile);
}