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

int main(void) {
	struct digit *start;
	start = readNumber();

	printf("The number ");
	printNumber(start);
	printf("was modified in %d places.\n", changeThrees(start));

	printf("The new number is ");
	printNumber(start);
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