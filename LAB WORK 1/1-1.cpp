#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter Array size :";
    cin >> size;

    int arr[size];

    cout << "Enter Array Elements :" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << " a" << "[" << i << "]" << " = ";
        cin >> arr[i];
    }

    cout << "Even Elements of an Array :" << endl;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            cout << arr[i] << "  ";
        }
    }
}