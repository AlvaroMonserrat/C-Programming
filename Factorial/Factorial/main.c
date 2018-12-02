#include<stdio.h>

int factorialOf(int number);


int main() {
	
	int result;
	int value;

	printf("Ingrese un numero entero: ");
	scanf_s("%d", &value);

	result = factorialOf(value);

	if (value >= 0) {
		printf("\nEl factorial del numero ingresado es: %d\n\n", result);
	}
	else {
		printf("Valor ingresado: %d\n", value);
	}

	system("pause");
	return 0;
}

int factorialOf(int number) {
	if (number == 1 || number == 0) {
		return 1;
	}
	else if (number > 0) {
		return number*factorialOf(number - 1);
	}
	else {
		printf("Error: valor ingresado no valido\n");
		return -1;
	}
}