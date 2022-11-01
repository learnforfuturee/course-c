#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char dataId[100][64];
char dataJudul[100][64];
char dataPenulis[100][64];
int indexPerpus = 0;
void getMenu();
void createData();
void readDatas();
void readData(int index);
void updateData();
void deleteData();
void searchData();
void deleteDataIndex(int index);
int searchId(char id[]);

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
		return 0;
	default:
		printf("Input Menu yang benar!!\n\n");
		goto backMenu;
		break;
	}
	printf("\n");
	system("pause");
	system("cls");
	goto backMenu;
}

void createData()
{
	char id[64], judul[64], penulis[64];
	printf("Masukkan Id Buku      : ");
	scanf("%s", id);
	printf("Masukkan Judul Buku   : ");
	scanf("%s", judul);
	printf("Masukkan Nama Penulis : ");
	scanf("%s", penulis);
	
	int index = searchId(id);
	
	if (index == -1) {
		strcpy(dataId[indexPerpus], id);
		strcpy(dataJudul[indexPerpus], judul);
		strcpy(dataPenulis[indexPerpus], penulis);
		
		indexPerpus++;
		printf("\nData berhasil di input\n");
	} else {
		printf("\nData sudah ada di database\n");
	}
}

void readDatas()
{
	int i;

	for (i = 0; i < indexPerpus; i++)
	{
		printf("----- %d -----\n", i + 1);
		readData(i);
	}
	if (i == 0 ) {
		printf("Data masih kosong\n");
	} else {
		printf("\nData berhasil ditampilkan\n");	
	}
}

void readData(int index)
{
	printf("Id\t\t : %s\n", dataId[index]);
	printf("Judul\t\t : %s\n", dataJudul[index]);
	printf("Penulis\t\t : %s\n", dataPenulis[index]);
}

void updateData()
{
	char updateId[64];
	char id[64], judul[64], penulis[64];
	printf("Masukkan Id Buku : ");
	scanf("%s", updateId);
	int index = searchId(updateId);

	if (index != -1)
	{
		printf("\nData Ditemukan!!\n\n");
		readData(index);

		printf("\n--- Update Your Data ---\n");
		
		printf("Update Id Buku      : ");
		scanf("%s", id);
		printf("Update Judul Buku   : ");
		scanf("%s", judul);
		printf("Update Nama Penulis : ");
		scanf("%s", penulis);

		strcpy(dataId[index], id);
		strcpy(dataJudul[index], judul);
		strcpy(dataPenulis[index], penulis);
	} else {
		printf("\nData Tidak Ditemukan!\n");
	}
}

void deleteData()
{
	char deleteId[64];
	printf("Masukkan Id Buku : ");
	scanf("%s", deleteId);
	int index = searchId(deleteId);

	if (index != -1)
	{
		deleteDataIndex(index);
		printf("\nData Berhasil Dihapus!\n");
	} else {
		printf("\nData Tidak Ditemukan!\n");
	}
}

void deleteDataIndex(int index)
{
	int i;
	for (i = index; i < indexPerpus; i++)
	{
		strcpy(dataId[index], dataId[index + 1]);
		strcpy(dataJudul[index], dataJudul[index + 1]);
		strcpy(dataPenulis[index], dataPenulis[index + 1]);
	}
	indexPerpus--;
}

void searchData() {
	char id[64];
	printf("Masukkan Id Buku : ");
	scanf("%s", id);
	int index = searchId(id);

	if (index != -1)
	{
		printf("\nData Ditemukan!!\n\n");
		readData(index);
	} else {
		printf("\nData Tidak Ditemukan!\n");
	}
}

int searchId(char id[])
{
	int i;
	for (i = 0; i < indexPerpus; i++)
	{
		if (strcmp(dataId[i], id) == 0)
		{
			return i;
		}
	}
	return -1;
}
