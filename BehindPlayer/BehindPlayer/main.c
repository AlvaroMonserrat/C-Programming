#include <stdio.h>

void behind(int *, int);

int main(void) {

	int array[10];
	int N, i;

	scanf_s("%d", &N);
	for (i = 0; i<N; i++) {
		scanf_s("%d", &array[i]);
	}

	behind(array, N);

	for (i = 0; i<N; i++) {
		printf("%d\n", array[i]);
	}

	system("pause");

	return 0;
}

void behind(int *ptrArray, int size) {

	int i;
	int biggestScore = 0;
	int temp;

	for (i = 0; i < size; i++)
	{
		temp = *(ptrArray + i);
		if (biggestScore < temp) {
			biggestScore = temp;
		}
	}

	for (i = 0; i < size; i++)
	{
		*(ptrArray + i) = biggestScore - *(ptrArray + i);
	}

}
