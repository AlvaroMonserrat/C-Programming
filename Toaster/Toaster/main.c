#include<stdio.h>

void amountOfData(char, int);

int main() {

	char dataType;
	int numberOfvariables;

	scanf_s("%c %d", dataType, numberOfvariables);

	//Function
	amountOfData(dataType, numberOfvariables);

	system("pause");
	return 0;
}

void amountOfData(char c, int n) {

	if (c == 'c') {

	}
	else if (c == 'i') {

	}
	else if (c == 's') {
		
	}
	else if (c == 'd') {

	}
	else {
		printf("Error en Tipo de dato ingresado\n");
	}
}