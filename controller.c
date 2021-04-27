#include <stdio.h>
#include <stdlib.h>

// Account Structure that creates a checkings and savings account
typedef struct AccountObj {
    int accountNum;
    int pinNum;
    int Checkings;
    int Savings;
} AccountObj;

typedef AccountObj *Account;

Account newAccount() {
  Account N = (struct AccountObj *)malloc(sizeof(AccountObj));
  int pin;
  int accNum;
  printf("Enter in an account number (0-100)\n");
  scanf("%d", &accNum);
  N->accountNum = accNum;
  printf("Enter in an pin number\n");
  scanf("%d", &pin);
  N->pinNum = pin;
  N->Checkings = 0;
  N->Savings   = 0;

  return N;
}

void cardSwipe(Account* accounts) {
    printf("(You Swipe your card but just enter in the account number you chose for your account and pretend thats the card swipe)\n");
    int num;
    int acc;
    int code;
    scanf("%d", &acc);
    if (accounts[acc] == NULL) {
        printf("The account number you entered was wrong\n");
        exit;
    } else {

        printf("Enter Pin Code:\n");
        scanf("%d", &code);
        while (accounts[acc]->pinNum != code) {
            printf("Incorrect Code, Try Again:\n");
            scanf("%d", &code);
        }

        printf("Select 1 for Checkings Acc and 2 for Savings Acc\n");
        scanf("%d", &num);

        if (num == 1) {
            printf("Your Checkings Balance is: $%d\n", accounts[acc]->Checkings);
            printf("Press 1 to Withdraw, 2 to Deposit, 3 to Exit\n");
            scanf("%d", &num);
            if (num == 1) {
                printf("How much do you want to Withdraw?\n");
                scanf("%d", &num);
                while (num > accounts[acc]->Checkings) {
                    printf("You don't have that much to withdraw, Enter an amount less than your balance of $%d\n", accounts[acc]->Checkings);
                    scanf("%d", &num);
                }
                accounts[acc]->Checkings -= num;
                printf("Successfully withdrew $%d amount, you now have $%d in your Checkings.\n", num, accounts[acc]->Checkings);
            } else if (num == 2) {
                printf("How much do you want to Deposit?\n");
                scanf("%d", &num);
                accounts[acc]->Checkings += num;
                printf("Successfully deposited $%d amount, you now have $%d in your Checkings.\n", num, accounts[acc]->Checkings);
            } else {
                exit;
            }

        } else if (num == 2) {
            printf("Your Savings Balance is: $%d\n", accounts[acc]->Savings);
            printf("Press 1 to Withdraw, 2 to Deposit, 3 to Exit\n");
            scanf("%d", &num);
            if (num == 1) {
                printf("How much do you want to Withdraw?\n");
                scanf("%d", &num);
                while (num > accounts[acc]->Savings) {
                    printf("You don't have that much to withdraw, Enter an amount less than your balance of $%d\n", accounts[acc]->Savings);
                    scanf("%d", &num);
                }
                accounts[acc]->Savings -= num;
                printf("Successfully withdrew $%d amount, you now have $%d in your Savings.\n", num, accounts[acc]->Savings);
            } else if (num == 2) {
                printf("How much do you want to Deposit?\n");
                scanf("%d", &num);
                accounts[acc]->Savings += num;
                printf("Successfully deposited $%d amount, you now have $%d in your Savings.\n", num, accounts[acc]->Savings);
            } else {
                exit;
            }
        } else {
            printf("invalid input, exiting menu\n");
        }
    }
}

// In main create a new account.
// Duplicate account numbers are
// currently not accounted for
void main() {
    Account accountList[101] = { NULL };

    printf("Press 1 to make an account, Press 2 to Swipe Card, Press 3 to Exit\n");
    int choice;
    scanf("%d", &choice);
    while (choice != 3) {
        if (choice == 1) {
            // Create a new account and add to array of accounts
            Account acc = newAccount();
            accountList[acc->accountNum] = acc;
        } else if (choice == 2) {
            cardSwipe(accountList);
        }
        printf("Press 1 to make an account, Press 2 to Swipe Card, Press 3 to Exit\n");
        scanf("%d", &choice);
    }
}