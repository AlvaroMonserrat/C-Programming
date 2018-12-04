/*Exercise: C Programming: Modular Programming and Memory Management.*/
#include<stdio.h>

void swapArray(int *);

int main() {

	int arrayOfsix[6];

	for (int i = 0; i < 6;i++)
	{
		scanf_s("%d", &arrayOfsix[i]);
	}

	//swap data
	swapArray(arrayOfsix);

	for (int i = 0; i < 6;i++)
	{
		printf("%d ", arrayOfsix[i]);

	}

	system("pause");
	return 0;
}

void swapArray(int *ptr) {

	int temp;
	int x = 0;
	int y = 5;

	while(x < y){
		temp = *(ptr + x);
		*(ptr + x) = *(ptr + y);
		*(ptr + y) = temp;
		x++;
		y--;
	}
}