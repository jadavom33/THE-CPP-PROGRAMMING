#include <iostream>
#include <string.h>
using namespace std;

class Train
{
private:
    int trainNumber;
    char trainName[20];
    char source[20];
    char destination[20];
    char trainTime[20];
    static int trainCount;

public:
    Train()
    {
        trainNumber = 0;
        strcpy(trainName, "NO NAME");
        strcpy(source, "NO SOURCE");
        strcpy(destination, "NO DESTINATION");
        strcpy(trainTime, "NO TIME");
        trainCount++;
    }

    // Parameterized Constructor
    Train(int number, const char name[], const char src[], const char dest[], const char time[])
    {
        trainNumber = number;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;
    }

    // Destructor
    ~Train()
    {
        trainCount--;
    }

    // Setter
    void setTrainDetails(int number, const char name[], const char src[], const char dest[], const char time[])
    {
        trainNumber = number;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
    }

    // Getter
    void getTrainDetails()
    {
        cout << endl;
        cout << "Train Number : " << trainNumber << endl;
        cout << "Train Name : " << trainName << endl;
        cout << "Source : " << source << endl;
        cout << "Destination : " << destination << endl;
        cout << "Train Time : " << trainTime << endl;
    }

    int getTrainNumber()
    {
        return trainNumber;
    }

    // Input Train Details
    void inputTrainDetails()
    {
        cout << "Enter Train Number: ";
        cin >> trainNumber;

        fflush(stdin);
        cout << "Enter Train Name: ";
        gets(trainName);

        fflush(stdin);
        cout << "Enter Source: ";
        gets(source);

        fflush(stdin);
        cout << "Enter Destination: ";
        gets(destination);

        fflush(stdin);
        cout << "Enter Train Time: ";
        gets(trainTime);
    }

    void displayTrainDetails()
    {
        getTrainDetails();
    }

    static int getTrainCount()
    {
        return trainCount;
    }
};

// Initialize Static Member
int Train::trainCount = 0;

class RailwaySystem
{
private:
    Train trains[20];
    int totalTrains;

public:
    RailwaySystem()
    {
        totalTrains = 0;
    }

    void addTrain()
    {
        if (totalTrains < 20)
        {
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
            cout << "Train Added Successfully" << endl;
        }
        else
        {
            cout << "Train List is Full" << endl;
        }
    }

    void displayAllTrains()
    {
        if (totalTrains == 0)
        {
            cout << "No Train Records Available" << endl;
            return;
        }

        for (int i = 0; i < totalTrains; i++)
        {
            trains[i].displayTrainDetails();
        }
    }

    void searchTrainByNumber(int number)
    {
        for (int i = 0; i < totalTrains; i++)
        {
            if (trains[i].getTrainNumber() == number)
            {
                cout << "Train Found :" << endl;
                trains[i].displayTrainDetails();
                return;
            }
        }

        cout << "Train Not Found!";
    }
};