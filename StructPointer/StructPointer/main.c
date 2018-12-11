#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


struct date {
	int year;
	int month;
	int day;
};

/* function prototypes */
void printDate(struct date);
void readDate(struct date *);
struct date advanceDay(struct date);



int main(void) {

	struct date today, tomorrow;

	readDate(&today);
	printDate(today);
	
	tomorrow = advanceDay(today);

	printDate(tomorrow);
	
	system("pause");
	return 0;
}

void printDate(struct date oneDay) {
	//month/day/year -> 01/05/1992
	if (oneDay.day > 9 && oneDay.month > 9) {
		printf("%d/%d/%d\n", oneDay.month, oneDay.day, oneDay.year);
	}
	else if (oneDay.day > 9 && oneDay.month < 10) {
		printf("0%d/%d/%d\n", oneDay.month, oneDay.day, oneDay.year);
	}
	else if (oneDay.day < 10 && oneDay.month > 9) {
		printf("%d/0%d/%d\n", oneDay.month, oneDay.day, oneDay.year);
	}
	else{
		printf("0%d/0%d/%d\n", oneDay.month, oneDay.day, oneDay.year);
	}
}

void readDate(struct date *ptrDate) {
	// year month day -> 2018 12 24 
	scanf("%d %d %d", &(ptrDate->year), &(ptrDate->month), &(ptrDate->day));
}

struct date advanceDay(struct date dayTom) {
	
	//months 31 days 
	if (dayTom.day == 31 && (dayTom.month == 1 || dayTom.month == 3 || dayTom.month == 5 || dayTom.month == 7 || dayTom.month == 8 || dayTom.month == 10 || dayTom.month == 12)) {
		dayTom.day = 1;
		if (dayTom.month == 12)
		{
			dayTom.month = 1;
			dayTom.year++;
		}
		else {
			dayTom.month++;
		}
	}//months 30 days 
	else if (dayTom.day == 30 && (dayTom.month == 4 || dayTom.month == 6 || dayTom.month == 9 || dayTom.month == 11)) {
		dayTom.day = 1;
		dayTom.month++;
	}//feb 28 days 
	else if (dayTom.day == 28 && dayTom.month == 2) {
		dayTom.day = 1;
		dayTom.month++;
	}
	else {
		dayTom.day++;
	}
	

	return dayTom;
}
