#include "BANK.CPP"

int main()
{
    SavingsAccount savings;
    CheckingAccount checking;
    FixedDepositAccount fixedDeposit;

    cout << "--------SAVINGS ACCOUNT--------" << endl;
    savings.setAccountDetails();
    savings.setSavingsDetails();
    cout << "--------CHECKINGS ACCOUNT--------" << endl;
    checking.setAccountDetails();
    checking.setOverdraftLimit();
    cout << "---------FIXED DEPOSIT ACCOUNT--------" << endl;
    fixedDeposit.setAccountDetails();
    fixedDeposit.setFixedDepositDetails();

    BankAccount *account;
    int choice;
    double amount;
    for (;;)
    {
        cout << "========================" << endl;
        cout << "---SERVICES AVAILABLE---" << endl;
        cout << "========================" << endl;
        cout << "1. Savings Account Information" << endl;
        cout << "2. Checking Account Information" << endl;
        cout << "3. Fixed Deposit Information" << endl;
        cout << "4. Deposit in Savings" << endl;
        cout << "5. Withdraw from Savings" << endl;
        cout << "6. Deposit in Checking" << endl;
        cout << "7. Withdraw from Checking" << endl;
        cout << "8. Savings Interest" << endl;
        cout << "9. Fixed Deposit Interest" << endl;
        cout << "10. Check Overdraft" << endl;
        cout << "11. Display All Balances" << endl;
        cout << "12. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "========SAVINGS ACCOUNT INFORMATION========" << endl;
            savings.displayAccountInfo();
            cout << "===========================================" << endl;
            break;
        case 2:
            cout << "========CHECKING ACCOUNT INFORMATION========" << endl;
            checking.displayAccountInfo();
            cout << "============================================" << endl;
            break;
        case 3:
            cout << "========FIXED DEPOSIT ACCOUNT INFORMATION========" << endl;
            fixedDeposit.displayAccountInfo();
            cout << "=================================================" << endl;
            break;
        case 4:
            cout << "========DEPOSIT IN SAVINGS========" << endl;
            cout << "Enter amount: ";
            cin >> amount;
            savings.deposit(amount);
            cout << "==================================" << endl;
            break;
        case 5:
            cout << "========WITHDRAW FROM SAVINGS========" << endl;
            cout << "Enter amount: ";
            cin >> amount;
            savings.withdraw(amount);
            cout << "=====================================" << endl;
            break;
        case 6:
            cout << "========DEPOSIT IN CHECKING========" << endl;
            cout << "Enter amount: ";
            cin >> amount;
            checking.deposit(amount);
            cout << "===================================" << endl;
            break;
        case 7:
            cout << "========WITHDRAW FROM CHECKING========" << endl;
            cout << "Enter amount: ";
            cin >> amount;
            checking.withdraw(amount);
            cout << "======================================" << endl;
            break;
        case 8:
            cout << "========SAVINGS INTEREST========" << endl;
            savings.calculateInterest();
            cout << "================================" << endl;
            break;
        case 9:
            cout << "========FIXED DEPOSIT INTEREST========" << endl;
            fixedDeposit.calculateInterest();
            cout << "======================================" << endl;
            break;
        case 10:
            cout << "========CHECK OVERDRAFT========" << endl;
            checking.checkOverdraft();
            cout << "===============================" << endl;
            break;
        case 11:
            cout << "========DISPLAYING ALL BALANCES========" << endl;
            cout << "Savings Balance : Rs. " << savings.getBalance() << endl;
            cout << "Checking Balance : Rs. " << checking.getBalance() << endl;
            cout << "Fixed Deposit   : Rs. " << fixedDeposit.getBalance() << endl;
            cout << "=======================================" << endl;
            break;
        case 12:
            cout << "========EXITING========" << endl;
            cout << "Exit." << endl;
            cout << "=======================" << endl;
            if (choice == 12)
            {
                return 0;
            }
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}