#include <iostream>
#include <string.h>
using namespace std;

class Vehicle
{
protected:
    int vehicleID;
    char manufacturer[20];
    char model[20];
    int year;
    static int totalvehicles;

public:
    Vehicle()
    {
        vehicleID = 0;
        strcpy(manufacturer, "NO MANUFACTURER");
        strcpy(model, "NO MODEL");
        year = 0;
    }

    ~Vehicle()
    {
    }

    void inputVehicleDetails()
    {
        cout << "Enter Vehicle ID: ";
        cin >> vehicleID;

        fflush(stdin);
        cout << "Enter Manufacturer: ";
        gets(manufacturer);

        fflush(stdin);
        cout << "Enter Model: ";
        gets(model);

        cout << "Enter Year: ";
        cin >> year;
    }

    void setVehicleDetails(int id, char manu[20], char mod[20], int y)
    {
        vehicleID = id;
        strcpy(manufacturer, manu);
        strcpy(model, mod);
        year = y;
    }

    int getVehicleID()
    {
        return vehicleID;
    }

    void getVehicleDetails()
    {
        cout << endl;
        cout << "Vehicle ID : " << vehicleID << endl;
        cout << "Manufacturer : " << manufacturer << endl;
        cout << "Model : " << model << endl;
        cout << "Year : " << year << endl;
    }

    void display()
    {
        getVehicleDetails();
    }
};

// static member
int Vehicle::totalvehicles = 10;

class Car : public Vehicle
{
protected:
    char fueltype[20];

public:
    void inputCarDetails()
    {
        inputVehicleDetails();
        fflush(stdin);
        cout << "Enter Fuel Type: ";
        gets(fueltype);
    }
};

class ElectricCar : public Car
{
protected:
    char batteryCapacity[20];

public:
    void inputElectricCarDetails()
    {
        inputCarDetails();
        cout << "Enter Battery Capacity: ";
        cin >> batteryCapacity;
    }
};

class Aircraft : public Vehicle
{
protected:
    int flightRange;

public:
    void inputAircraftDetails()
    {
        inputVehicleDetails();
        cout << "Enter Flight Range: ";
        cin >> flightRange;
    }
};

class FlyingCar : public Aircraft
{
public:
    void inputFlyingCarDetails()
    {
        inputAircraftDetails();
    }
};

class SportsCar : public ElectricCar
{
    int topSpeed;

public:
    void inputSportsCarDetails()
    {
        inputElectricCarDetails();
        cout << "Enter Top Speed: ";
        cin >> topSpeed;
    }
};

class Sedan : public Car
{
};

class SUV : public Car
{
};
// Vehicle Registry class
class VehicleRegistry
{
    Vehicle vehicles[20];
    int totalVehicles;
    int choice;

public:
    VehicleRegistry()
    {
        totalVehicles = 0;
    }

    Car car;
    ElectricCar electricCar;
    Aircraft aircraft;
    FlyingCar flyingCar;
    SportsCar sportsCar;
    Sedan sedan;
    SUV suv;
    void addVehicle()
    {
        cout << "What type of Vehicle do you want to add?" << endl;
        cout << "1. Car" << endl;
        cout << "2. Electric Car" << endl;
        cout << "3. Aircraft" << endl;
        cout << "4. Flying Car" << endl;
        cout << "5. Sports Car" << endl;
        cout << "6. Sedan" << endl;
        cout << "7. SUV" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            car.inputCarDetails();
            vehicles[totalVehicles] = car;
            totalVehicles++;
            break;
        case 2:
            electricCar.inputElectricCarDetails();
            vehicles[totalVehicles] = electricCar;
            totalVehicles++;
            break;
        case 3:
            aircraft.inputAircraftDetails();
            vehicles[totalVehicles] = aircraft;
            totalVehicles++;
            break;
        case 4:
            flyingCar.inputFlyingCarDetails();
            vehicles[totalVehicles] = flyingCar;
            totalVehicles++;
            break;

        case 5:
            sportsCar.inputSportsCarDetails();
            vehicles[totalVehicles] = sportsCar;
            totalVehicles++;
            break;
        case 6:
            sedan.inputCarDetails();
            vehicles[totalVehicles] = sedan;
            totalVehicles++;
            break;
        case 7:
            suv.inputVehicleDetails();
            vehicles[totalVehicles] = suv;
            totalVehicles++;
            break;
        default:
            cout << "Invalid Choice" << endl;
        }
    }

    void displayAllVehicles()
    {
        if (totalVehicles == 0)
        {
            cout << "No Vehicle Records Available" << endl;
            return;
        }

        for (int i = 0; i < totalVehicles; i++)
        {
            vehicles[i].display();
        }
    }

    void searchVehicleByID(int id)
    {
        for (int i = 0; i < totalVehicles; i++)
        {
            if (vehicles[i].getVehicleID() == id)
            {
                cout << "Vehicle Found :" << endl;
                vehicles[i].display();
                return;
            }
        }

        cout << "Vehicle Not Found" << endl;
    }
};