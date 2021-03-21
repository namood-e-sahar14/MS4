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
#include <stdio.h>
#ifndef ACCOUNT_H_
#define ACCOUNT_h_
struct Demographic
{
	int    birth_year;
	double income;
	char   resident_of_country[11];
};

struct UserLogin
{
	char login[31];
	char displayed_name[11];
	char password[9];
};

struct Account
{
	int account_num;
	char account_type;
	struct UserLogin user_login;
	struct Demographic demographic;
};


void getAccount(struct Account *account);
void getUserLogin(struct Account *account);
void getDemographic(struct Account *account);


#pragma once
#endif