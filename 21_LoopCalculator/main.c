#include <stdio.h>
#include <stdbool.h>

/* A simple REPL calculator for console. */

double operation(char, double, double);

int main(void) {
	// Show instructions
	printf("Commands for REPL calculator:\n");
	printf(" [] = number -> Set given number to current value.\n");
	printf(" [] + number -> Add given number to current value\n");
	printf("                and set result to current value.\n");
	printf(" [] - number -> Substract number from current value\n");
	printf("                and set result to current value.\n");
	printf(" [] * number -> Mulltiplly number and current value\n");
	printf("                and set result to current value.\n\n");
	
	
	// REPL
	double current = 0, n;
	char op;
	
	while(true)
	{
		printf("[%.4f] ", current);
		scanf("\n%c%lf", &op, &n);
		current = operation(op, current, n);
	}
	
	return 0;
}

double operation(char op, double current, double number)
{
	switch(op)
	{
		case '=':
			return number;
		case '+':
			return current + number;
		case '-':
			return current - number;
		case '*':
			return current * number;
		case '^':
			{
				double res = 1; int i;
				for(i = 0; i < number; i++)
					res *= current;
			
				return res;
			}
		default:
			printf("\n  Unknown operator.\n\n");
			return current;
	}
}
