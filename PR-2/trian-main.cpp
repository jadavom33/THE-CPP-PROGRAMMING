#include "2-1.cpp"

int main()
{
    RailwaySystem railway;
    int choice, number;

    for (;;)
    {
        cout << endl;
        cout << "1. Add New Train Record" << endl;
        cout << "2. Display All Train Records" << endl;
        cout << "3. Search Train by Number" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            railway.addTrain();
            break;

        case 2:
            railway.displayAllTrains();
            break;

        case 3:
            cout << "Enter Train Number : ";
            cin >> number;
            railway.searchTrainByNumber(number);
            break;

        case 4:
            cout << "Exiting the system. Goodbye!" << endl;
            if (choice == 4)
            {
                return 0;
            }

            break;

        default:
            cout << "Invalid Choice";
        }
    }
}