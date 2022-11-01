#include <stdio.h>

char dataId[100][64];
char dataJudul[100][64];
char dataPenulis[100][64];
int indexPerpus = 0;
void getMenu();
void createData();
void readDatas();
void readData(int index);

int main() {
	
	getMenu();
		
	return 0;
}

void getMenu() {
	int menu;
	backMenu:
	printf("----- SELAMAT DATANG DI SISTEM PERPUSTAKAAN -----\n");
	printf("1. Create Data\n");
	printf("2. Read Data\n");
	printf("3. Update Data\n");
	printf("4. Delete Data\n");	
	printf("5. Search Data\n");
	printf("6. Exit\n");
	printf("Masukkan Menu : ");
	scanf("%d", &menu);
	printf("\n");
	
	switch(menu)
	{
	case 1: 
		createData();
		break;
	case 2: 
		readDatas();
		break;
	case 3: 
		// updateData();
		break;
	case 4: 
		// deleteData();
		break;
	case 5: 
		// Search Data
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

void createData() {
	printf("Masukkan Id Buku      : "); scanf("%s", dataId[indexPerpus]);
	printf("Masukkan Judul Buku   : "); scanf("%s", dataJudul[indexPerpus]);
	printf("Masukkan Nama Penulis : ");	scanf("%s", dataPenulis[indexPerpus]);
	
	indexPerpus++;
}

void readDatas() {
	int i;
	
	for(i = 0; i < indexPerpus;i++) {
		printf("----- %d -----\n", i+1);
		readData(i);
	}
}

void readData(int index) {
	printf("Id\t\t : %s\n", dataId[index]);
	printf("Judul\t\t : %s\n", dataJudul[index]);
	printf("Penulis\t\t : %s\n\n", dataPenulis[index]);
}
