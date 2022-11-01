#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

void getMenu();
void createData();
void readDatas();
void readData(char id[]);
void updateData();
void deleteData();
void searchData();
void deleteDataId(char id[]);
bool searchId(char id[]);

int main()
{
	getMenu();

	return 0;
}

void getMenu()
{
	int menu;
backMenu:
	printf("----- SELAMAT DATANG DI SISTEM PERPUSTAKAAN -----\n\n");
	printf("1. Create Data\n");
	printf("2. Read Data\n");
	printf("3. Update Data\n");
	printf("4. Delete Data\n");
	printf("5. Search Data\n");
	printf("6. Exit\n");
	printf("Masukkan Menu : ");
	scanf("%d", &menu);
	printf("\n");

	switch (menu)
	{
	case 1:
		createData();
		break;
	case 2:
		readDatas();
		break;
	case 3:
		updateData();
		break;
	case 4:
		deleteData();
		break;
	case 5:
		searchData();
		break;
	case 6:
		goto finish;
	default:
		printf("Input Menu yang benar!!\n\n");
		goto backMenu;
		break;
	}
	printf("\n");
	system("pause");
	system("cls");
	goto backMenu;
	finish:
	printf("Program berakhir\n");
}

void createData()
{
	FILE *create = fopen("data.txt", "a+");
	char id[64], judul[64], penulis[64];
	printf("Masukkan Id Buku      : ");
	scanf("%s", id);
	printf("Masukkan Judul Buku   : ");
	scanf("%s", judul);
	printf("Masukkan Nama Penulis : ");
	scanf("%s", penulis);
	
	bool index = searchId(id);
	
	if (!index) {
		fprintf(create, "%s#%s#%s\n", id, judul, penulis);
		printf("\nData berhasil di input\n");
	} else {
		printf("\nData sudah ada di database\n");
	}
	
	fclose(create);
}

void readDatas()
{
	int i = 0;
	char id[64], judul[64], penulis[64];
	FILE *read = fopen("data.txt", "r");
	
	while(fscanf(read, "%[^#]#%[^#]#%[^\n]\n", id, judul, penulis) != EOF) {
		printf("----- %d -----\n", i + 1);
		printf("Id\t\t : %s\n", id);
		printf("Judul\t\t : %s\n", judul);
		printf("Penulis\t\t : %s\n", penulis);
		i++;
	}
	
	if (i == 0 ) {
		printf("Data masih kosong\n");
	} else {
		printf("\nData berhasil ditampilkan\n");	
	}
	fclose(read);
}

void updateData()
{
	FILE *baca = fopen("data.txt", "r");
	FILE *write = fopen("buffer.txt", "w");
	char updateId[64];
	char id[64], judul[64], penulis[64];
	char dataId[64], dataJudul[64], dataPenulis[64];
	
	printf("Masukkan Id Buku : ");
	scanf(" %s", updateId);
	bool index = searchId(updateId);

	if (index)
	{
		printf("\nData Ditemukan!!\n\n");
		readData(updateId);

		printf("\n--- Update Your Data ---\n");
		
		printf("Update Id Buku      : ");
		scanf(" %s", id);
		printf("Update Judul Buku   : ");
		scanf(" %s", judul);
		printf("Update Nama Penulis : ");
		scanf(" %s", penulis);
		
		while(fscanf(baca, "%[^#]#%[^#]#%[^\n]\n", dataId, dataJudul, dataPenulis) != EOF) {
			if (strcmp(dataId, updateId) == 0) {
				fprintf(write, "%s#%s#%s\n", id, judul, penulis);
				printf("Data Berhasil di update");
			} else {
				fprintf(write, "%s#%s#%s\n", dataId, dataJudul, dataPenulis);
			}
		}
	} else {
		printf("\nData Tidak Ditemukan!\n");
	}
	
	fclose(baca);
	fclose(write);
	
	remove("data.txt");
	rename("buffer.txt", "data.txt");
}

void deleteData()
{
	char deleteId[64];
	printf("Masukkan Id Buku : ");
	scanf(" %s", deleteId);
	bool index = searchId(deleteId);

	if (index)
	{
		deleteDataId(deleteId);
	} else {
		printf("\nData Tidak Ditemukan!\n");
	}
}

void deleteDataId(char id[])
{
	FILE *write = fopen("buffer.txt", "w");
	FILE *baca = fopen("data.txt", "r");
	char dataId[64], dataJudul[64], dataPenulis[64];
	
	while(fscanf(baca, "%[^#]#%[^#]#%[^\n]\n", dataId, dataJudul, dataPenulis) != EOF) {
		if (strcmp(dataId, id) == 0) {
			printf("\nData Berhasil Dihapus!\n");
		} else {
			fprintf(write, "%s#%s#%s\n", dataId, dataJudul, dataPenulis);
		}
	}
	fclose(baca);
	fclose(write);
	
	remove("data.txt");
	rename("buffer.txt", "data.txt");
}

void searchData() {
	char id[64]; 
	printf("Masukkan Id Buku : ");
	scanf("%s", id);
	bool index = searchId(id);

	if (index)
	{
		printf("\nData Ditemukan!!\n\n");
		readData(id);
	} else {
		printf("\nData Tidak Ditemukan!\n");
	}
}

bool searchId(char id[]) {
	char dataId[64], dataJudul[64], dataPenulis[64];
	FILE *read = fopen("data.txt", "r");
	
	while(fscanf(read, "%[^#]#%[^#]#%[^\n]\n", dataId, dataJudul, dataPenulis) != EOF) {
		if (strcmp(dataId, id) == 0)
		{
			fclose(read);
			return true;
		}
	}
	fclose(read);
	return false;
}

void readData(char id[]) {
	char dataId[64], dataJudul[64], dataPenulis[64];
	FILE *read = fopen("data.txt", "r");
	
	while(fscanf(read, "%[^#]#%[^#]#%[^\n]\n", dataId, dataJudul, dataPenulis) != EOF) {
		if (strcmp(dataId, id) == 0)
		{
			printf("Id\t\t : %s\n", dataId);
			printf("Judul\t\t : %s\n", dataJudul);
			printf("Penulis\t\t : %s\n", dataPenulis);
		}
	}
	fclose(read);
}
