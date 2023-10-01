#include <stdio.h>
#include <time.h>

int main() {

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	int present_day = tm.tm_mday;
	int present_month = tm.tm_mon + 1;
	int present_year = tm.tm_year + 1900;

	int bday_day;
	int bday_month;
	int bday_year;

	int month_day_number[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	printf("Type your birthday year: ");
	scanf("%d", &bday_year);

	if (bday_year > present_year) {
		printf("Select a valid year.\n");
		return 1;
	}

	printf("Type your birthday month: ");
	scanf("%d", &bday_month);

	if (bday_month > 12 || bday_month < 1) {
		printf("Select a valid month.\n");
		return 1;
	}

	printf("Type your birthday day: ");
	scanf("%d", &bday_day);

	if (bday_day > month_day_number[bday_month-1] || bday_day < 1) {
		printf("%d", month_day_number[bday_month-1]);
		printf("Select a valid day.\n");
		return 1;
	}

	if (bday_day > present_day) {
		present_day = present_day + month_day_number[bday_month - 1];
		present_month = present_month - 1;
	}
	if (bday_month > present_month) {
		present_year = present_year - 1;
		present_month = present_month - 1;
	}

	int age_day = present_day - bday_day;
	int age_month = present_month - bday_month;
	int age_year = present_year - bday_year;

	printf("Present Age: %d Years, %d Months and %d Days. \n", age_year, age_month, age_day);
	return 0;
}
