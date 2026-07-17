#include <iostream>
using namespace std;

int main()
{
    int num1, num2;
    cout << "Enter the first Number :";
    cin >> num1;
    cout << "Enter the second Number :";
    cin >> num2;

    int arr[100];
    int j = 0;

    for (int i = num1; i <= num2; i += 4)
    {
        if (i % 4 == 0)
        {
            arr[j] = i;
            j++;
        }
    }
    cout << "The array is: ";
    for (int i = 0; i < j; i++)
    {
        cout << arr [i] << " ";
    }
}