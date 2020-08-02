#pragma warning(disable : 4996)
#include<iostream>

using namespace std;

typedef struct list{
	struct list *next;
	struct list *prev;
	char znak;
}lista;

void add_next(char dodawany, list **ostatni) {
	lista *nowy;
	nowy = (lista *)malloc(sizeof(lista));
	nowy->znak = dodawany;
	nowy->next = NULL;
	nowy->prev = *ostatni;
	(*ostatni)->next = nowy;
	(*ostatni) = (*ostatni)->next;
}

void add_prev(char dodawany, list **pierwszy) {
	lista *nowy;
	nowy = (lista *)malloc(sizeof(lista));
	nowy->znak = dodawany;
	nowy->next = *pierwszy;
	nowy->prev = NULL;
	(*pierwszy)->prev = nowy;
	(*pierwszy) = (*pierwszy)->prev;
}

void delete_back(list **ostatni) {
	list *usuwany = (*ostatni);
	(*ostatni) = (*ostatni)->prev;
	(*ostatni)->next = NULL;
	free(usuwany);
}

void delete_front(list **pierwszy) {
	list *usuwany = (*pierwszy);
	(*pierwszy) = (*pierwszy)->next;
	(*pierwszy)->prev = NULL;
	free(usuwany);
}



int main() {
	lista *pierwszy, *ostatni;
	pierwszy = (lista*)malloc(sizeof(lista));
	pierwszy->next = NULL;
	pierwszy->prev = NULL;
	ostatni = (lista*)malloc(sizeof(lista));
	ostatni = pierwszy;
	int width, heigth, moves;
	scanf("%i %i %i", &width, &heigth, &moves);
	int x, y, size;
	scanf("%i %i %i", &y, &x, &size);
	x--;
	y--;
	char a;
	for (int i = 0; i < size; i++) {
		cin >> a;
		if (i == 0) {
			pierwszy->znak = a;
		}
		else {
			add_next(a, &ostatni);
		}
	}
	char **field = (char **)malloc(heigth * sizeof(char*));
	for (int i = 0; i < heigth; i++) {
		field[i] = (char *)malloc(width * sizeof(char));
	}
	for (int i = 0; i < heigth; i++) {
		for (int j = 0; j < width; j++) {
			cin >> field[i][j];
		}
	}
	char dir = '4';
	for (int i = 1; i < moves; i++) {
		if (field[x][y] == '1')dir = '1';
		else if (field[x][y] == '2')dir = '2';
		else if (field[x][y] == '3')dir = '3';
		else if (field[x][y] == '4')dir = '4';
		else if (field[x][y] == '#');
		else if (field[x][y] >= 97 && field[x][y] <= 122) {
			add_prev(field[x][y], &pierwszy);
			size++;
			field[x][y]--;
		}
		else if (field[x][y] >= 65 && field[x][y] <= 90) {
			add_next(field[x][y] + 32, &ostatni);
			size++;
			field[x][y]--;
		}
		else if (field[x][y] = 96) {
			if (size > 1)delete_front(&pierwszy);
			size--;
		}
		else if (field[x][y] = 64) {
			if(size > 1)delete_back(&ostatni);
			size--;
		}
		if (size == 0)break;
		//ruch
		if (dir == '1') {
			if (x == 0)x = heigth - 1;
			else x--;
		}
		else if (dir == '2') {
			if (x == heigth - 1)x = 0;
			else x++;
		}
		else if (dir == '3') {
			if (y == 0)y = width - 1;
			else y--;
		}
		else if (dir == '4') {
			if (y == width - 1)y = 0;
			else y++;
		}
	}
	if (size != 0) {
		if (field[x][y] == '1')dir = '1';
		else if (field[x][y] == '2')dir = '2';
		else if (field[x][y] == '3')dir = '3';
		else if (field[x][y] == '4')dir = '4';
		else if (field[x][y] == '#');
		else if (field[x][y] >= 97 && field[x][y] <= 122) {
			add_prev(field[x][y], &pierwszy);
			size++;
			field[x][y]--;
		}
		else if (field[x][y] >= 65 && field[x][y] <= 90) {
			add_next(field[x][y] + 32, &ostatni);
			size++;
			field[x][y]--;
		}
		else if (field[x][y] = 96) {
			if (size > 1)delete_front(&pierwszy);
			size--;
		}
		else if (field[x][y] = 64) {
			if (size > 1)delete_back(&ostatni);
			size--;
		}
	}
	if (size == 0) {
		printf("%d %d", y + 1, x + 1);
		printf(" #");
		printf("\n");
	}
	else {
		printf("%d %d ", y + 1, x + 1);
		for (int i = 0; i < size; i++) {
			printf("%c", pierwszy->znak);
			pierwszy = pierwszy->next;
		}
		printf("\n");
	}

	for (int i = 0; i < heigth; i++) {
		for (int j = 0; j < width; j++) {
			if (field[i][j] == 'a' - 1) {
				printf("@");
			}
			else printf("%c", field[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < heigth; i++) {
		free(field[i]);
	}
	free(field);
	return 0;
}

