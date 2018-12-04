/*Exercise: C Programming: Modular Programming and Memory Management.*/
#include<stdio.h>

// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ....
int fibonacci(int); 
// 6453->>> 6 + 4 + 5 + 3 = 18
int sumOfDigits(int);

int main() {

	int n,fib;
	int dig = 6;
	printf("Ingrese un numero: \n");
	scanf_s("%d", &n);

	if (n >= 0) {
		fib = fibonacci(n);
		printf("Numero Fibonacci es: %d\n", fib);
	}
	else {
		printf("Error: numero ingresado incorrecto\n");
	}

	dig=sumOfDigits(6453);
	printf("numero: %d\n", dig);


	system("pause");
	return 0;
}


int fibonacci(int number) {
	if (number == 1) {
		return 0;
	}
	else if (number == 2) {
		return 1;
	}
	else {
		return fibonacci(number - 1) + fibonacci(number-2);
	}
}

int sumOfDigits(int y) {

	if (y == 0) {
		return 0;
	}

	return  (y % 10) + sumOfDigits(y/10);
}