/*
	==================================================
	Assignment #1 Milestone #3
	==================================================
	Name   : Namood-e-sehar
	ID     : 121979207
	Email  :Namood-e-sahar@myseneca.ca
	Section:NFF
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include "commonHelpers.h"
#include "account.h"
#include "accountTicketingUI.h"

// currentYear defination from pdf
int currentYear(void)
{
	time_t currentTime = time(NULL);
	return localtime(&currentTime)->tm_year + 1900;
}

// clearStandardInputBuffer  defination from pdf
void clearStandardInputBuffer(void)
{
	while (getchar() != '\n')
	{
		;
	}
}

// getInteger defination
int getInteger(void)
{
	int int_value, num = 1;
	char newLine = 'x';

	while (num == 1)
	{
		scanf("%d%c", &int_value, &newLine);
		if (newLine == '\n')
		{
			num = 0;
		}
		else
		{
			clearStandardInputBuffer();
			printf("ERROR: Enter an integer value: ");
		}
	}
	return int_value;
}

// get IntPositive defination
int getPositiveInteger(void)
{
	int value, num;
	num = 1;

	while (num == 1)
	{
		//scanf("%d", &value);
		value = getInteger();
		if (value < 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		if (value > 0) {
			num = 0;
		}
	}
	return value;
}

// getDouble defination
double getDouble(void)
{
	double db_value;
	int num = 1;
	char newLine = 'x';

	while (num == 1)
	{
		scanf("%lf%c", &db_value, &newLine);
		if (newLine == '\n')
		{
			num = 0;
		}
		else
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be a double floating-point number: ");
		}
	}
	return db_value;
}

// get DoublePositive definataion
double getPositiveDouble(void)
{
	double value;
	int num = 1;
	while (num == 1)
	{
		//scanf("%lf",&dblA);
		value = getDouble();

		if (value < 0.0)
		{
			printf("ERROR: Value must be a positive double floating-point number: ");
		}
		if (value > 0.0)
		{
			num = 0;
		}
	}

	return value;
}

// getIntFromRange defination
int getIntFromRange(int lower_bound, int upper_bound)
{
	int value, num;
	num = 1;

	while (num == 1) {
		value = getInteger();
		if (value < lower_bound || value > upper_bound)
		{
			clearStandardInputBuffer();
			printf("Value must be between %d and %d inclusive:", lower_bound, upper_bound);
		}
		else {
			num = 0;
		}
	}
	return value;
}

// get CharoOption function defination
char getCharOption(char* string_arr)
{
	char my_char;
	char newLine = 'x';
	char my_sub_char;
	int num = 1, found = 0, str_size;
	str_size = strlen(string_arr);

	while (num == 1) {
		scanf("%c%c", &my_char, &newLine);
		for (int i = 0;i < str_size;i++)
		{
			my_sub_char = string_arr[i];
			if (my_char == my_sub_char)
			{
				found = 1;
				break;
			}
		}

		if (found == 0)
		{
			clearStandardInputBuffer();
			printf("Character must be one of [%s]: ", string_arr);
		}
		else {
			num = 0;
		}
	}
	return my_char;
}

// getCstring
void getCString(char* string_arr, int minimum, int maximum)
{
	int num = 1, my_size;
	char my_str[100], newLine = 'x';
	while (num == 1)
	{
		//scanf("%s", &my_str, &newLine);
		//scanf("%s%c", &my_str, &newLine);
		//scanf("%[^\n]%c", &my_str, &newLine);
		scanf("%[^\n]", &my_str);
		my_size = strlen(my_str);
		if (minimum != maximum && (my_size < minimum || my_size > maximum))
		{
			clearStandardInputBuffer();
			printf("string length must be no more than %d chars: ", maximum);
		}
		else if (minimum == maximum && my_size != minimum)
		{
			clearStandardInputBuffer();
			printf("string length must be exactly %d chars: ", minimum);
		}
		else if ((minimum != maximum && (my_size >= minimum || my_size <= maximum))
			|| (minimum == maximum && my_size == minimum))
		{
			clearStandardInputBuffer();
			strcpy(string_arr, my_str);
			num = 0;
		}
	}
}



