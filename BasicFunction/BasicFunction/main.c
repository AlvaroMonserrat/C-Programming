#include<stdio.h>


int sum(int x, int y) {

	return x+y;
}


int main() {

	int a, b;
	int result;

	printf("Ingrese un numero: \n");
	scanf_s("%d", &a);
	printf("Ingrese otro numero: \n");
	scanf_s("%d", &b);

	printf("Los numeros son %d y %d.\n", a, b);

	result = sum(a, b);
	printf("La suma es: %d\n", result);
	

	system("pause");


	return 0;
}