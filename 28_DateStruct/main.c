#include <stdio.h>
#include <stdbool.h>

/* This program manages dates and 
 * contains functions to update them.
 */
 
//Struct for date
struct date {
	int day;
	int month;
	int year;
};

// Functions for date struct
struct date updateDate(struct date);
void displayDate(struct date);

// Start point
int main(void) {
	struct date d;
	
	printf("Initialize date (DD/MM/YYYY) > ");
	scanf("%i/%i/%i", &d.day, &d.month, &d.year);

	while(true)
	{
		displayDate(d);
		d = updateDate(d);
		getchar();
	}
	
	return 0;
}

// Get date for next day
struct date updateDate(struct date d)
{
	int daysInMonth(struct date);
	
	//Update day
	if(d.day >= daysInMonth(d))
	{
		d.day = 1;
		
		// Update month
		if(d.month >= 12)
		{
			d.month = 1;
			
			// Update year
			++d.year;
		} else {
			++d.month;
		}
	} else {
		++d.day;
	}
	
	return d;
}

// Show date on console
void displayDate(struct date d)
{
	printf("%.2i/%.2i/%.4i\n", d.day, d.month, d.year);
}

// Algorithms to check is a year is leap
bool isLeapYear(struct date d)
{
	if(d.year % 4 == 0)
	{
		if(d.year % 100 == 0 && d.year % 400 != 0)
		{
			return false;
		} else {
			return true;
		}
	} else {
		return false;
	}
}

// Return quantity of days in the current
// month of the given date.
int daysInMonth(struct date d)
{
	bool isLeapYear(struct date);
	
	static int daysForMonth[] = 
	  { 31, 28, 31, 30,
	    31, 30, 31, 31,
		30, 31, 30, 31 };
	
	if(isLeapYear(d) && d.month == 2)
		return 29;
	else
		return daysForMonth[d.month - 1];
}
