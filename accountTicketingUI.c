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
#include "account.h"
#include "commonHelpers.h"
#include "accountTicketingUI.h"

void applicationStartup(struct Account accounts[], int arrSize)
{
    int index, i, go = 1;
    char loggedin_user_type;
    while (go == 1) {

        index = menuLogin(accounts, arrSize);
         
        if (index == -1) {
            go = 0; 
        }
        else {
            loggedin_user_type = accounts[index].account_type;
            if (loggedin_user_type == 'A') {
                menuAgent(accounts, arrSize, accounts[index]);
            }
            else {
                printf("CUSTOMER: Home Menu Currently Unavailable\n");
                printf("<< ENTER key to Continue... >>\n");
                clearStandardInputBuffer();
            }
        }

    }
}

int menuLogin(struct Account accounts[], int arrSize)
{
    int selection, go = 1, account_num, i, found;

    while (go == 1)
    {

        printf("======================================\n");
        printf("Account Ticketing System - Login\n");
        printf("======================================\n");
        printf("1) Login to the system\n");
        printf("0) Exit application\n");
        printf("-----------------------------------------\n");

        printf("Selection: ");
        selection = getInteger();

        if (selection != 0 && selection != 1) 
        {
            printf("ERROR: Value must be between 0 and 1 inclusive:\n");
        }
        else if (selection == 0)
        {
            return -1;
        }
        else if (selection == 1)
        {
            found = -1;
            // enter account num
            printf("Enter your account#: ");
            account_num = getPositiveInteger();
            for (i = 0; i < arrSize; i++) {
                if (accounts[i].account_num == account_num) {
                    found = i;
                    break;
                }
            }

            if (found != -1) {
                return found;
            }
            else {
                printf("ERROR: Access Denied.\n");
                printf("<< ENTER key to Continue... >>\n");
                clearStandardInputBuffer();
            }
        }
    }
}

void menuAgent(struct Account accounts[], int arrSize, struct Account loggedin_user)
{
    int selection, go = 1, account_num, i, found;

    while (go == 1) {

        printf("\nAGENT: %s (%d)\n", loggedin_user.user_login.displayed_name, loggedin_user.account_num);
        printf("======================================\n");
        printf("Account Ticketing System - Agent Menu\n");
        printf("======================================\n");
        printf("1) Add a new account\n");
        printf("2) Modify an existing account\n");
        printf("3) Remove an account\n");
        printf("4) List accounts: summary view\n");
        printf("5) List accounts: detailed view\n");
        printf("-----------------------------------------\n");
        printf("0) Logout\n");

        printf("Selection: ");
        selection = getInteger();

        if (selection < 0 && selection > 5) {
            printf("Invalid Selection\n");
        }
        else if (selection == 0)
        {
            go = 0;
        }
        else if (selection == 1)
        {
            found = -1;
            for (i = 0; i < arrSize; i++) {
                if (accounts[i].account_num == 0) {
                    found = i;
                    break;
                }
            }

            if (found != -1) {
                getAccount(&accounts[found]);
            }
            else {
                printf("ERROR: Account listing is FULL, call ITS Support!\n");
                printf("<< ENTER key to Continue... >>\n");
                clearStandardInputBuffer();
            }
        }
        else if (selection == 2)
        {
            found = -1;
            // enter account num
            printf("Enter account number: ");
            account_num = getPositiveInteger();
            for (i = 0; i < arrSize; i++) {
                if (accounts[i].account_num == account_num) {
                    found = i;
                }
            }

            if (found != -1) {
                updateAccount(&accounts[found], arrSize);
            }
            else {
                printf("Account Number not found.\n");
                printf("<< ENTER key to Continue... >>   [ENTER]\n");
                clearStandardInputBuffer();
            }
        }
        else if (selection == 3)
        {
            found = -1;
           
            printf("Enter account number: ");
            account_num = getPositiveInteger();
            for (i = 0; i < arrSize; i++) {
                if (accounts[i].account_num == account_num) {
                    found = i;
                }
            }
            if (found != -1) {
                if (account_num == loggedin_user.account_num) {
                    printf("You cannot delete logged in user.\n");
                    printf("<< ENTER key to Continue... >>    [ENTER]\n");
                    clearStandardInputBuffer();
                }
                else {
                    char approval;
                    printf("Do you realy want to delete the account? ");
                    char acc_type[3] = { 'Y', 'N', '\n' };
                    approval = getCharOption(acc_type);

                    if (approval == 'Y') {
                        accounts[found].account_num = 0;
                    }
                    else {
                        printf("Account delete confirmation declined.\n");
                        printf("<< ENTER key to Continue... >>   [ENTER]\n");
                        clearStandardInputBuffer();
                    }
                }
            }
            else {
                printf("Account Number not found.\n");
                printf("<< ENTER key to Continue... >>   [ENTER]\n");
                clearStandardInputBuffer();
            }
        }
        else if (selection == 4) {
            displayAllAccountsSummaryRecords(accounts, sizeof(accounts));
        }
        else if (selection == 5) {
            displayAllAccountsDetailRecords(accounts, sizeof(accounts));
        }
    }
}
  /*int findAccountIndexByAcctNum(int acc_num, struct Account, int arrsize, char acc_type)
{
    {
            found = -1;
            for (i = 0; i < arrSize; i++) {
                if (accounts[i].account_num == 0) {
                    found = i;
                    break;
                }
            }

            if (found != -1) {
                getAccount(&accounts[found]);
            }
            else {
                printf("ERROR: Account listing is FULL, call ITS Support!\n");
                printf("<< ENTER key to Continue... >>\n");
                clearStandardInputBuffer();
            }
        }
        else if (selection == 2)
        {
            found = -1;
            // enter account num
            printf("Enter account number: ");
            account_num = getPositiveInteger();
            for (i = 0; i < arrSize; i++) {
                if (accounts[i].account_num == account_num) {
                    found = i;
                }
            }

            if (found != -1) {
                updateAccount(&accounts[found], arrSize);
            }
            else {
                printf("Account Number not found.\n");
                printf("<< ENTER key to Continue... >>\n");
                clearStandardInputBuffer();
            }
        }
}
*/
void updateAccount(struct Account *account_to_update, int arrSize)
{
    //display selection
    int selection, go = 1, account_type;

    while (go == 1) {

        printf("\nAccount: %d - Update Options\n", account_to_update->account_num);
        printf("-----------------------------------------\n");
        printf("1) Update current account type (current value: %c)\n", account_to_update->account_type);
        printf("2) Login\n");
        printf("3) Demographics\n");
        printf("0) Done\n");
        printf("Selection: ");
        selection = getInteger();

        if (selection < 0 && selection > 3) {
            printf("Invalid Selection\n");
        }
        else if (selection == 0)
        {
            go = 0;
        }
        else if (selection == 1)
        {
            printf("Enter the account type (A=Agent | C=Customer): ");
            char acc_type[3] = { 'A', 'C', '\n' };
            account_to_update->account_type = getCharOption(acc_type);
        }
        else if (selection == 2)
        {
            updateUserLogin(&account_to_update->user_login);

        }
        else if (selection == 3)
        {
            updateDemographic(&account_to_update->demographic);
        }

    }

}

void updateUserLogin(struct UserLogin *login_to_update)
{
    //display selection
    int selection, go = 1;
    while (go == 1)
    {

        printf("\nUser Login: %s - Update Options\n", login_to_update->login);
        printf("-----------------------------------------\n");
        printf("1) Display Name(current value: %s)\n", login_to_update->displayed_name);
        printf("2) Password\n");
        printf("0) Done\n");
        printf("Selection: ");
        selection = getInteger();

        if (selection < 0 || selection > 2)
        {
            printf("invalid selection");
        }
        else if (selection == 1)
        {
            printf("Enter the display name (30 chars max): ");
            getCString(login_to_update->displayed_name, 10, 30);
        }
        else if (selection == 2)
        {
            printf("Enter the password (must be 8 chars in length): ");
            getCString(login_to_update->password, 8, 8);
        }

        else if (selection == 0)
        {
            go = 0;
        }
    }

}

void updateDemographic(struct Demographic *demographic_to_update)
{
    //display selection
    int selection, go = 1;
    printf("\nDemographic Update Options\n");
    printf("-----------------------------------------\n");
    printf("1) Household income (current value: %lf )\n", demographic_to_update->income);
    printf("2) Country (current value: %s)\n", demographic_to_update->resident_of_country);
    printf("0) Done\n");

    while (go == 1)
    {

        printf("Selection: ");
        selection = getInteger();

        if (selection < 0 || selection > 2)
        {
            printf("invalid selection");
        }
        else if (selection == 1)
        {
            printf("Enter the household Income: ");
            demographic_to_update->income = getPositiveDouble();
        }
        else if (selection == 2)
        {
            printf("Enter the country (30 chars max.): ");
            getCString(demographic_to_update->resident_of_country, 3, 30);
        }
        else if (selection == 0)
        {
            go = 0;
        }
    }

}

void displayAccountSummaryHeader()
{
    printf("\nAcct# Acct.Type Birth\n");
    printf("----- -------- ------\n");
}

void displayAccountSummaryRecord(struct Account accounts)
{
    printf("%05d", accounts.account_num);
    if (accounts.account_type == 'c')
    {
        printf(" %-9s", "customer");
    }
    else
    {
        printf(" %-9s", "agent");
    }
    printf(" %5d", accounts.demographic.birth_year);
    printf("\n");
}

void displayAllAccountsSummaryRecords(struct Account accounts[], int arrSize)
{
    displayAccountSummaryHeader();
    int i;
    for (i = 0;i <= arrSize;i++) {
        displayAccountSummaryRecord(accounts[i]);
    }
}   

void displayAccountDetailHeader()
{
    printf("Acct# Acct.Type Birth Income Country Disp.Name Login Password\n");
    printf("----- --------- ----- ----------- ---------- --------------- ---------- --------\n");

}

void displayAllAccountsDetailRecords(struct Account accounts[], int arrsize)
{
    displayAccountDetailHeader();
    int i;
    for (i = 0; i <= arrsize; i++) {
        displayAccountDetailRecord(accounts[i]);
    }
}

void displayAccountDetailRecord(struct Account accounts)
{
printf("%05d", accounts.account_num);
    if (accounts.account_type == 'C')
    {
       printf(" %-9s", "CUSTOMER");
    }
    else
    {
       printf(" %-9s", "AGENT");
    }
    printf(" %5d", accounts.demographic.birth_year);
    printf(" $%10.2lf", accounts.demographic.income);
    printf(" %-10s", accounts.demographic.resident_of_country);
    printf(" %-15s", accounts.user_login.login);
    printf(" %-10s", accounts.user_login.displayed_name);
    int i;
    for (i = 0;i < 8;i++)
    {
        if ((i % 2) != 0) {
           printf("*");
        }
       else {
           printf("%c", accounts.user_login.password[i]);        
        }
    }
    printf("\n");

}

void pauseExecution()

{
    printf("<< ENTER key to Continue... >>");
    clearStandardInputBuffer();
    putchar('\n');
}

