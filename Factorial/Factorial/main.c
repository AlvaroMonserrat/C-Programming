#include<stdio.h>

int factorialOf(int number);


int main() {
	
	int result;
	int value;

	printf("Ingrese un numero entero: ");
	scanf_s("%d", &value);

	result = factorialOf(value);

	printf("\nEl factorial del numero ingresado es: %d\n\n", result);

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
		printf("Error: valor ingresado no valido");
		return -1;
	}
}