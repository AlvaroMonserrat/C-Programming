#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


struct point {
	int x;
	int y;
};


void printPoint(struct point);
void printPoly(struct point *, int);
void initializePoly(struct point *, int);

int main() {

	int amountOf;
	struct point *figure;
	scanf("%d", &amountOf);

	figure = (struct point*)malloc(amountOf * sizeof(struct point));

	initializePoly(figure, amountOf);

	printPoly(figure, amountOf);

	free(figure);
	system("pause");
	return 0;
}


void printPoint(struct point data){
	printf("(%d, %d)\n", data.x, data.y);
}


void printPoly(struct point *ptrData, int num) {
	int i = 0;
	for (i;i < num;i++) {
		printPoint(ptrData[i]);
	}
}

void initializePoly(struct point *ptrData, int num) {
	int i = 0;
	for (i;i < num;i++) {
		(ptrData + i)->x = -i;  
		(ptrData + i)->y = i*i;
	}
}