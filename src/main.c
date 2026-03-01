/* main.c */
#include <stdio.h>
#include <stdbool.h>

bool isLeap(int year) {
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

long DateToDays (int day, int month, int year) {
	long days = 0;
	for (int y = 1970; y < year; y++) {
		if (isLeap (y)) {
			days += 366;
		} else {
			days += 365;
		}
	}

	for (int m = 1; m < month; m++) {
		switch (m) {
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				days += 31;
				break;
			case 4: case 6: case 9: case 11:
				days += 30;
				break;
			case 2:	
				if (isLeap (year)) {
					days += 29;
					break;
				} else {
					days += 28;
					break;
				}
		}
	}

	return days + day;
}

void main (void)
{
	int day, month, year;
	printf ("Enter date as dd/mm/yyyy:\n");
	scanf ("%d/%d/%d", &day, &month, &year);

	if ((day < 1 || day > 31) || (month < 1 || month > 12) || (year < 1970)
			|| (month > 3 && year > 2026)) {
		printf ("Invalid date!\n");
	}

	long fix_days = DateToDays (1, 1, 1970);
	long days = DateToDays (day, month, year);

	printf ("Days since 1/1/1970: %ld\n", days - fix_days);
}
