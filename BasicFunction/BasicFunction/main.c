/*--------------------------------------------------------------------------------
	Dartmouth_IMTx: DART.IMT.C.03
	C Programming: Modular Programming and Memory Management
	Unit 3.1: Functions and recursion.
---------------------------------------------------------------------------------*/
#include<stdio.h>

#define MAX_ARRAYSIZE (50)

void metricFunction(int n, double *a, char *b);

int main(void) {

	double inputData[MAX_ARRAYSIZE];
	char inputDataType[MAX_ARRAYSIZE];
	int numberOfData;

	scanf_s("%d", &numberOfData);

	/*Conversión de datos*/
	metricFunction(numberOfData, inputData, inputDataType);

	system("pause");

	return 0;
}


void metricFunction(int n, double *a, char *b) {

	for (int i = 0;i < n;i++) {
		scanf_s("%lf %c", &a[i], &b[i]);
		if (b[i] == 'm') {
			a[i] = (a[i] / 0.3048);
			
		}
		else if (b[i] == 'g')
		{
			a[i] = (a[i] * 0.002205);
		
		}
		else if (b[i] == 'c')
		{
			a[i] = (a[i]*1.8+ 32 );
	
		}
	}

	printf("\n");

	for (int i = 0;i < n;i++) {
		printf("%.6lf ", a[i]);
		
		if (b[i] == 'm') {
			printf("ft\n");
		}
		else if (b[i] == 'g')
		{
			printf("lbs\n");
		}
		else if (b[i] == 'c')
		{
			printf("f\n");
		}
		

	}
}

/*
	1 foot = 0.3048 meters;
	1 gram = 0.002205 pounds;
	temperature in degrees Fahrenheit = 32 + 1.8 × temperature in degrees Celsius.
*/