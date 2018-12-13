#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct digit {
	int num;
	struct digit *next;
};

// Write your prototypes here
int divisibleByThree(struct digit *);
void printNumber(struct digit *start);
void freeNumber(struct digit *start);
struct digit *readNumber(void);
struct digit * append(struct digit * end, struct digit * newDigptr);
struct digit *createDigit(int dig);
int changeThrees(struct digit *);
int countRedun(struct digit *);
void putDigit(struct digit *, int);
int isExistDig(struct digit *start, int digit);
int howManyTime(struct digit *start, int digit);

int main(void) {
	struct digit *start;
	start = readNumber();

	printf("The number ");
	printNumber(start);

	printf("contains %d redundancies.\n", countRedun(start));

	freeNumber(start);
	system("pause");
	return 0;
}

struct digit *createDigit(int dig) {
	struct digit *ptr;
	ptr = (struct digit *) malloc(sizeof(struct digit));
	ptr->num = dig;
	ptr->next = NULL;
	return ptr;
}

struct digit * append(struct digit * end, struct digit * newDigptr) {
	end->next = newDigptr;
	return(end->next);
}

void printNumber(struct digit *start) {
	struct digit * ptr = start;
	while (ptr != NULL) {
		printf("%d", ptr->num);
		ptr = ptr->next;
	}
	printf("\n");
}

void freeNumber(struct digit *start) {
	struct digit * ptr = start;
	struct digit * tmp;
	while (ptr != NULL) {
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
}

struct digit *readNumber(void) {
	char c;
	int d;
	struct digit *start, *end = NULL, *newptr;
	start = NULL;
	scanf("%c", &c);
	while (c != '\n') {
		d = c - 48;
		newptr = createDigit(d);
		if (start == NULL) {
			start = newptr;
			end = start;
		}
		else {
			end = append(end, newptr);
		}
		scanf("%c", &c);
	}
	return(start);
}

// Write your divisibleByThree() function here
int divisibleByThree(struct digit *start) {

	struct digit * ptr = start;
	int qsum = 0;
	while (ptr != NULL) {
		qsum += ptr->num;
		ptr = ptr->next;
	}
	if (qsum % 3 == 0) return 1;
	else return 0;

}

int changeThrees(struct digit *start) {

	struct digit *ptr = start;
	int number = 9;
	int countDigit = 0;
	while (ptr != NULL) {
		if (ptr->num == 3) {
			ptr->num = number;
			countDigit++;
		}
		ptr = ptr->next;
	}
	return countDigit;
}

void putDigit(struct digit *start, int newdig) {
	struct digit *ptr = start;
	struct digit *newptr = NULL;

	newptr = createDigit(newdig);

	while (ptr->next != NULL) {
		ptr = ptr->next; //Avanzar al final de la lista existente
	}
	ptr->next = newptr; //Enlazar nuevo digito con la lista
}

//si existe el digito retorna un 1;
int isExistDig(struct digit *start, int digit) {
	
	struct digit *ptr = start;
	int checkDigit = 0;
	while (ptr != NULL) {
		if (ptr->num == digit) {
			checkDigit = 1;
		}
		ptr = ptr->next; //Avanzar al final de la lista existente
	}
	return checkDigit;
}

int howManyTime(struct digit *start, int digit) {
	struct digit *ptr = start;
	int countDigit = 0;

	while (ptr != NULL) {
		if (ptr->num == digit) {
			countDigit++;
		}
		ptr = ptr->next;
	}
	return countDigit;
}

int countRedun(struct digit *start) {

	struct digit *ptr = start;
	struct digit *nstart = NULL; // new linked list
	struct digit *nptr = NULL;
	
	int countTotal = 0;
	int countTime = 0;

	if (ptr != NULL) {
		nstart = createDigit(ptr->num);
		ptr = ptr->next;
	}
	
	while (ptr != NULL)
	{
		if (!isExistDig(nstart, ptr->num)) {
			putDigit(nstart, ptr->num);
		}
		ptr = ptr->next;
	}
	
	nptr = nstart;

	while (nptr != NULL) {

		countTime = howManyTime(start, nptr->num);
		if (countTime) {
			countTotal += (countTime - 1);
		}
		nptr = nptr->next;
	}

	freeNumber(nstart);
	return countTotal;
}