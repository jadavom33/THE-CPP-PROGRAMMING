#include <iostream>
#include <string.h>
using namespace std;

class BankAccount
{
protected:
    int accountNumber;
    char accountHolderName[20];
    double balance;

public:
    void setBalance(double amount)
    {
        balance = amount;
    }
    void setAccountDetails()
    {
        cout << "Enter your Account Number :";
        cin >> accountNumber;

        fflush(stdin);
        cout << "Enter the Account Holder name :";
        gets(accountHolderName);

        cout << "Enter Account Balance :";
        cin >> balance;
    }
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance = balance + amount;
            cout << "Amount deposited successfully." << endl;
        }
        else
        {
            cout << "Invalid amount." << endl;
        }
    }
    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance = balance - amount;
            cout << "Amount withdrawn successfully." << endl;
        }
        else
        {
            cout << "Insufficient balance." << endl;
        }
    }
    double getBalance()
    {
        return balance;
    }
    void calculateInterest()
    {
        cout << "Interest calculation not available." << endl;
    }
    void displayAccountInfo()
    {
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Holder : " << accountHolderName << endl;
        cout << "Balance        : Rs. " << balance << endl;
    }
};

class SavingsAccount : public BankAccount
{
private:
    float interestRate;

public:
    void setSavingsDetails()
    {
        cout << "Enter the rate of Savings Account : ";
        cin >> interestRate;
    }
    void calculateInterest()
    {
        double interest;

        interest = getBalance() * interestRate / 100;

        cout << "Interest Rate : " << interestRate << "%" << endl;
        cout << "Interest      : Rs. " << interest << endl;
    }

    void displayAccountInfo()
    {
        BankAccount::displayAccountInfo();
        cout << "Interest Rate : " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    void setOverdraftLimit()
    {
        cout << "Enter the overdraft Limit :";
        cin >> overdraftLimit;
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= getBalance())
        {
            BankAccount::withdraw(amount);
        }
        else if (amount > 0 && amount <= getBalance() + overdraftLimit)
        {
            setBalance(getBalance() - amount);
            cout << "Withdrawal successful using overdraft."
                 << endl;
        }
        else
        {
            cout << "Overdraft limit exceeded." << endl;
        }
    }

    void checkOverdraft()
    {
        cout << "Overdraft Limit : Rs. "
             << overdraftLimit << endl;
    }

    void displayAccountInfo()
    {
        BankAccount::displayAccountInfo();
        cout << "Overdraft Limit : Rs. "
             << overdraftLimit << endl;
    }
};

class FixedDepositAccount : public BankAccount
{
private:
    float term;
    float interestRate;

public:
    void setFixedDepositDetails()
    {
        cout << "Enter the Term(duration in months) : ";
        cin >> term;
        cout << "Enter the rate of Fixed Deposit Account : ";
        cin >> interestRate;
    }

    void calculateInterest()
    {
        double interest;
        interest = getBalance() * interestRate * term / (12 * 100);
        cout << "Interest Rate : " << interestRate << "%" << endl;
        cout << "Term          : " << term << " months" << endl;
        cout << "Interest      : Rs. " << interest << endl;
    }
    void displayAccountInfo()
    {
        BankAccount::displayAccountInfo();
        cout << "Term          : " << term << " months" << endl;
        cout << "Interest Rate : " << interestRate << "%" << endl;
    }
};