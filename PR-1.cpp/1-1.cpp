#include <iostream>
using namespace std;

class TimeConverter
{
public:
    int h, s, m, total ;
};

int main()
{
    TimeConverter t1;
    int  fevorite;

    cout << "1. HH:MM:SS to Seconds" << endl;
    cout << "2. Seconds to HH:MM:SS" << endl;
    cout << "Enter your choice: ";
    cin >> fevorite;

    switch ( fevorite)
    {
    case 1:
        cout << "Enter hours : ";
        cin >> t1.h;

        cout << "Enter minutes : ";
        cin >> t1.m;

        cout << "Enter seconds : ";
        cin >> t1.s;

        t1.total = (t1.h * 3600) + (t1.m * 60) + t1.s;

        cout << "Total seconds: " << t1.total << endl;
        break;

    case 2:
        cout << "Enter seconds : ";
        cin >> t1.total;

        t1.h = t1.total / 3600;
        t1.m = (t1.total % 3600) / 60;
        t1.s = t1.total % 60;

        cout << "HH : MM : SS => "
             << t1.h << ":" << t1.m << ":" << t1.s  << endl;
        break;

    default:
        cout << "Invalid choice." << endl;
        break;
    }

}