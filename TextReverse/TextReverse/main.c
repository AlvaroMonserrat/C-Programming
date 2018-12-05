#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//Texto:
/*Science Computer on Papers Selected Knuth, Ervin Donald ― correct." be will results the that reader a 
convince to and works algorithm an way the communicate to concepts, mathematical as well as forms literary 
and aesthetic traditional with works who essayist an ideally is programmer A clearly. them understand can 
beings human that so and quickly them perform can machines computing that so written are programs best "The*/

int main() {
	
	char words[68][15];  // 68 palabras de 15 caracteres cada una

	int i = 0;

	//Escribir Texto
	for (i = 0; i < 68; i++) {
		scanf("%s", words[i]);
	}
	printf("\n");

	//Imprimir Texto
	for (i = 0; i < 68; i++) {
		printf("%s ", words[67-i]);
	}

	printf("\n");

	system("pause");

	return 0;
}