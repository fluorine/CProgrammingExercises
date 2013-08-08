#include <stdio.h>

/* This program uses a structure to represent
 * time and shows how functions can use it.
 */
 
// Structure for time
struct time {
	int hour;
	int minute;
	int second;
};

// Functions for management of time structure
struct time updateTime(struct time);
struct time displayTime(struct time);

int main() {
	struct time d = {0, 0, 0};
	while(1)
	{
		displayTime(d);
		d = updateTime(d);
		getchar();
	}
	return 0;
}

// Update time one second at the same time
struct time updateTime(struct time d)
{
	// For seconds
	if(d.second == 59)
	{
		d.second = 0;
		
		// For minutes
		if(d.minute == 59)
		{
			d.minute = 0;
			
			// For hours
			if(d.hour == 23)
			{
				d.hour = 0;
			} else {
				d.hour++;
			}
		} else {
			d.minute++;
		}
	} else {
		d.second++;
	}
	
	return d;
}

// Display time on console
struct time displayTime(struct time d)
{
	printf("%.2i:%.2i:%.2i\n", 
	       d.hour, d.minute, d.second);
}
