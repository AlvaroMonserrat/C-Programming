#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


void amountOfData(char, int);
int numberOfDig(int y);
void printBytesOf(int data);


int main() {

	
	char dataType;
	int numberOfvariables;

	scanf("%c %d", &dataType, &numberOfvariables);
	
	//Function
	amountOfData(dataType, numberOfvariables);

	system("pause");
	return 0;
}

void amountOfData(char c, int n) {
	
	int xAmount = 0;

	if (c == 'c') {
		xAmount = n * sizeof(char);
		printBytesOf(xAmount);
		
	}
	else if (c == 'i') {
		xAmount = n * sizeof(int);
		printBytesOf(xAmount);
	
	}
	else if (c == 's') {
		xAmount = n * sizeof(short);
		printBytesOf(xAmount);
	}
	else if (c == 'd') {
		xAmount = n * sizeof(double);
		printBytesOf(xAmount);
	}
	else {
		printf("Error en Tipo de dato ingresado\n");
	}
}

int numberOfDig(int y) {
	int count = 0;

	for (int i = 0; y != 0; i++) {
		y = y / 10;
		count++;
	}

	return count;
}

void printBytesOf(int data) {

	int countDig = 0;

	countDig = numberOfDig(data);
	if (countDig <= 6 && countDig > 3) {
		printf("%d KB and %d B\n", data / 1000, data % 1000);
	}
	else if (countDig <= 3) {
		printf("%d B\n", data % 1000);
	}
	else if (countDig > 6 && countDig <= 9) {
		printf("%d MB and %d KB and %d B\n", data / 1000000, (data % 1000000) / 1000, data % 1000);
	}
	else {
		printf("Cantidad sobre 1T\n");
	}

}