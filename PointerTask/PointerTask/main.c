#include<stdio.h>

void elixirFuction(int*);

int main() {


	int age;
	int *ageAdr = &age;

	scanf_s("%d", &age);
	printf("Your current age is %d.\n", age);

	elixirFuction(ageAdr);

	printf("Your new age will be %d!\n", age);


	system("pause");

	return 0;
}

void elixirFuction(int *ptr) {

	if (*ptr < 21) {
		*ptr = *ptr * 2;
	}
	else
	{
		*ptr = *ptr - 10;
	}

}