#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


struct student {
	char name[50];
	int age;
	struct student *next;

};

struct student * createStudent(char *, int);
struct student *append(struct student * end, struct student * newStudptr);
void printStudents(struct student *start);
void freeStudents(struct student *start);

int main() {

	struct student *start, *newStudptr, *end, *tmp;
	int ageP, ageR, ageM;

	scanf("%d %d %d", &ageP, &ageR, &ageM);

	start = createStudent("Petra", ageP);
	end = start;

	newStudptr = createStudent("Remi", ageR);
	end = append(end, newStudptr);

	newStudptr = createStudent("Mike", ageM);
	end = append(end, newStudptr);

	printStudents(start);

	freeStudents(start);

	system("pause");
	return 0;
}


struct student * createStudent(char *nameStudent, int ageStudent) {

	struct student *ptr = NULL;
	ptr = (struct student *)malloc(sizeof(struct student));

	int i;
	char flag = 'a';
	for (i = 0; flag != '\0'; i++) {
		ptr->name[i] = *(nameStudent + i);
		flag = ptr->name[i];
	}
	
	ptr->age = ageStudent;
	ptr->next = NULL;

	return ptr;

}

struct student *append(struct student * end, struct student * newStudptr) {
	
	end->next = newStudptr;
	end = newStudptr;

	return end;
}

void printStudents(struct student *start) {

	while (start != NULL)
	{
		printf("%s is %d years old.\n", start->name, start->age);
		start = start->next;
	}

}

void freeStudents(struct student *start) {

	struct student *ptr, *tmp;
	ptr = start;

	while (ptr != NULL) {
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
}