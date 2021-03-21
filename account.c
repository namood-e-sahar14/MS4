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
#include <time.h>
#include "account.h"
#include "commonHelpers.h"
#include "accountTicketingUI.h"

void getAccount(struct Account *account)
{
	printf(" Account Data:New Record\n----------------------------------------\n");
	printf("Enter the account number: ");
	account->account_num = getPositiveInteger();
	printf("Enter the account type (A=Agent | C=Customer): ");
	char acc_type[3] = { 'A', 'C', '\n' };
	account->account_type = getCharOption(acc_type);
}
void  getUserLogin(struct Account *account)
{
	printf("\nUser Login Data Input\n----------------------------------------\n");                 
	printf("Enter user login (10 chars max): ");
	getCString(account->user_login.login, 3, 10);
	printf("Enter the display name (30 chars max): ");
	getCString(account->user_login.displayed_name, 10, 30);
	printf("Enter the password (must be 8 chars in length): ");
	getCString(account->user_login.password, 8, 8);
}
void  getDemographic(struct Account *account)
{ 
printf("\nDemographic Data Input\n----------------------------------------\n");                
printf("Enter birth year (current age must be between 18 and 110): ");
int cYear = currentYear();
account->demographic.birth_year = getIntFromRange(cYear - 110, cYear - 18);
printf("Enter the household Income: ");
account->demographic.income = getPositiveDouble();
printf("Enter the country (30 chars max.): ");
getCString(account->demographic.resident_of_country, 3, 10);
}