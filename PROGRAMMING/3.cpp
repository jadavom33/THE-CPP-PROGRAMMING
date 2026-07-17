#include <iostream>
using namespace std;

int main()
{
    int num1, num2;
    cout << "Enter First number :";
    cin >> num1;
    cout << "Enter Second number :";
    cin >> num2;

    cout << "Multiplication table from " << num1 << " to " << num2 << " :" << endl;
    for (int i = num1; i <= num2; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cout << i << " * " << j << " = " << i * j << endl;
        }
        cout << endl;
    }
    return 0;
}