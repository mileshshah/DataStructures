#include <stdio.h>
#include <stdlib.h>

int getNumberOfDigits(int num)
{
	int count = 0;

	while(num > 0)
	{
		num /= 10;
		count++;
	}

	return count;
}

void print_digit(int num)
{
	int temp = num;
	int num_of_digits = getNumberOfDigits(temp);
	char *res = (char*)malloc(sizeof(char)*num_of_digits);

	for(int i = num_of_digits - 1; i >= 0; i--)
	{
		int digit = num % 10;
		num /= 10;
		*(res+i) = ('0'+digit);
	}
	for(int i = 0; i < num_of_digits; i++)
	{
		putchar(*(res+i));
	}
	putchar('\n');
}

void main(int argc, char* argv[])
{
	int d = 0;
	printf("What digit do you want to print? ");
	scanf("%d",&d);
	print_digit(d);
}
