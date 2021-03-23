#pragma once
/*
	==================================================
	Assignment #1 Milestone #3
	==================================================
	Name   : Namood-e-sehar
	ID     : 121979207
	Email  :Namood-e-sahar@myseneca.ca
	Section:NFF
*/

#pragma once
#ifndef COMMON_HELPERS_
#define COMMON_HELPERS_
#include <stdio.h>
int currentYear(void);
void clearStandardInputBuffer(void);
int getInteger(void);
int getPositiveInteger(void);
double getDouble(void);
double getPositiveDouble(void);
int getIntFromRange(int lower_bound, int upper_bound);
char getCharOption(char *string_arr);
void getCString(char *string, int minimum, int maximum);
#endif //COMMON_HELPERS_
#pragma once
