/*
	==================================================
	Assignment #1 Milestone #3
	==================================================
	Name   : Namood-e-sehar
	ID     : 121979207
	Email  :Namood-e-sahar@myseneca.ca
	Section:NFF
*/
#ifndef ACCOUNTTICKETINGUI_H_
#define ACCOUNTTICKETINGUI_H_

void displayAccountSummaryHeader(void);
void displayAccountDetailHeader(void);
void displayAccountSummaryRecord(struct Account accounts);
void displayAccountDetailRecord(struct Account accounts);

void applicationStartup(struct Account accounts[], int account_size);
int menuLogin(struct Account accounts[], int account_size);
void menuAgent(struct Account accounts[], int account_size, struct Account loggedin_user);

int findAccountIndexByAcctNum(int acc_num_to_find, struct Account accounts[], int arrsize, int prompt_acc_num);
void displayAllAccountsSummaryRecords(struct Account accounts[], int arrSize);
void displayAllAccountsDetailRecords(struct Account accounts[], int arrSize);

void pauseExecution(void);
void updateAccount(struct Account *account_to_update, int arrSize);
void updateUserLogin(struct UserLogin *userlogin_to_update);
void updateDemographic(struct Demographic *demo_to_update);

#endif // !ACCOUNTTICKETINGUI_H_