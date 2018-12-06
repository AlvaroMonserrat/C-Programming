#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
// Be sure to include any other library you may need...

// Write your allocateString() prototype here
char * allocateString(int);

int main(void) {
	int lengthLight, lengthDark;
	char *strLight, *strDark;

	scanf("%d %d", &lengthLight, &lengthDark);
	// Write a line of code here that calls the function allocateString(). 
	strLight = allocateString(lengthLight + 1);
	/* The goal is to reserve space for the light setting label, therefore you
	need to pass the number (lengthLight+1) to the function allocateString()
	(the +1 is there to reserve space for the null terminator).
	Store the return value of this function call in the variable strLight. */

	// Write a line of code here that calls the function allocateString().
	strDark = allocateString(lengthDark + 1);
	/* This time the goal is to reserve space in memory for the dark setting label.
	Store the return value of the function call in the variable strDark. */

	scanf("%s", strLight);
	scanf("%s", strDark);
	printf("Local settings: %s - %s\n", strLight, strDark);
	// Write a line of code here to free the memory allocated for strLight
	free(strLight);
	// Write a line of code here to free the memory allocated for strDark
	free(strDark);
	system("pause");

	return 0;
}

char * allocateString(int numChars) {
	// declare your variable(s) here
	char *ptr;
	// Write a line of code here that performs the memory allocation.
	ptr = (char *)malloc(numChars * sizeof(char));
	/* You should allocate space in memory for the number of characters specified
	via the input parameter to the function and store the address of the
	allocated memory in a pointer named ptr. In order to receive credit for your
	solution you need to use sizeof(char) in this line, even if sizeof(char)
	returns 1. */

	return ptr;
}