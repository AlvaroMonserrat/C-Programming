#include<stdio.h>

int numberOfByte(int);

int main() {

	int cant = 0;
	int cantOfByte = 0;
	scanf_s("%d", &cant);

	cantOfByte = numberOfByte(cant);

	if (cantOfByte != -1) {
		printf("%d bytes\n", cantOfByte);
	}
	else {
		printf("Tipo de codigo ingresado no Valido\n");
	}
	
	system("pause");
	return 0;
}

int numberOfByte(int number) {

	int result = 0;
	int flag = 0;
	int cantOf;
	char typeOf;

	for (int i = 0; i < number; i++) {
		scanf_s("%d %c", &cantOf,&typeOf);
		if (typeOf == 'c') {
			result = result + cantOf * sizeof(char);
		}
		else if(typeOf == 'i') {
			result = result + cantOf * sizeof(int);
		}else if (typeOf == 'd') {
			result = result + cantOf * sizeof(double);
		}
		else {
			flag = -1;
		}
	}

	if (flag != -1)
	{
		return result;
	}
	else {
		return flag;
	}

}