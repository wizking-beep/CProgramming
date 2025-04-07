#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BALANCE_FILE "balance.txt"
#define TRANSACTIONS_FILE "transactions.txt"

double loadBalance() {
    FILE *file = fopen(BALANCE_FILE, "r");
    double balance = 0.0;
    if (file == NULL) {
        printf("Balance file not found. Starting with balance ksh0.00\n");
        return 0.0;
    }

    if (fscanf(file, "%lf", &balance) != 1) {
        printf("Could not read balance from file. Starting with balance ksh0.00\n");
        balance = 0.0;
    }
    fclose(file);
    return balance;
}

void displayBalance(double balance) {
    printf("Your balance is: ksh%.2lf\n", balance);
}

void saveBalance(double balance) {
    FILE *file = fopen(BALANCE_FILE, "w");
    if (file == NULL) {
        perror("Error opening balance file for writing");
        return;
    }
    fprintf(file, "%.2lf\n", balance);
    fclose(file);
}

void logTransaction(const char *type, double amount, double currentBalance) {
    FILE *file = fopen(TRANSACTIONS_FILE, "a");
    if (file == NULL) {
        perror("Error opening transaction file for logging");
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char time_str[20];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", t);

    fprintf(file, "[%s] Type: %-10s | Amount: ksh%9.2f | New Balance: ksh%.2f\n",
            time_str, type, amount, currentBalance);
    fclose(file);
}

void fund(double *balance) {
    double amount;
    printf("Enter the amount to fund: ");
    if (scanf("%lf", &amount) != 1) {
        printf("Invalid input.\n");
        return;
    }
    if (amount > 0) {
        *balance += amount;
        printf("You deposited ksh%.2lf\n", amount);
        printf("Your new balance is: ksh%.2lf\n", *balance);
        logTransaction("Deposit", amount, *balance);
    } else {
        printf("Invalid amount\n");
    }
}

void withdraw(double *balance) {
    double withdrawAmount;
    printf("Enter the amount to withdraw: ");
    if (scanf("%lf", &withdrawAmount) != 1) {
        printf("Invalid input.\n");
        return;
    }
    if (withdrawAmount <= 0) {
        printf("Invalid amount, try again\n");
    } else if (withdrawAmount > *balance) {
        printf("Insufficient balance\n");
        printf("Your current balance is ksh%.2lf\n", *balance);
    } else {
        *balance -= withdrawAmount;
        printf("Successful withdrawal of ksh%.2lf\n", withdrawAmount);
        printf("New balance is ksh%.2lf\n", *balance);
        logTransaction("Withdrawal", withdrawAmount, *balance);
    }
}

void miniStatement() {
    FILE *file = fopen(TRANSACTIONS_FILE, "r");
    char line[256];

    printf("\n--- Mini Statement ---\n");

    if (file == NULL) {
        printf("No transactions recorded yet.\n");
    } else {
        int transactionsFound = 0;
        while (fgets(line, sizeof(line), file) != NULL) {
            printf("%s", line);
            transactionsFound = 1;
        }
        if (!transactionsFound) {
            printf("No transactions recorded yet.\n");
        }
        fclose(file);
    }
    printf("----------------------\n");
}

int main() {
    double balance = loadBalance();  
    unsigned short choice = 0;

    do {
        printf("\nATM Management System\n");
        printf("1. Check account balance\n");
        printf("2. Fund your account\n");
        printf("3. Withdraw funds\n");
        printf("4. Print your mini statement\n");
        printf("5. Exit\n");
        printf("Choose action: ");

        if (scanf("%hu", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            while(getchar() != '\n');
            continue;
        }

        switch(choice) {
            case 1:
                displayBalance(balance);
                break;
            case 2:
                fund(&balance);
                saveBalance(balance);
                break;
            case 3:
                withdraw(&balance);
                saveBalance(balance);
                break;
            case 4:
                miniStatement();
                break;
            case 5:
                printf("Exited\n");
                break;
            default:
                printf("Your choice is invalid\n");
        }
    } while (choice != 5);  

    return 0;
}
