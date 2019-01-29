/**
 * OOPs Lab 2019 4th SEM
 * NAME : Jayjeet Chakraborty (17CS8036)
 * ASSIGNMENT : Pyramid Printing
 * DATE : 25/01/2019
 */

#include <iostream>
#include <iomanip>

using namespace std;

int hieght;
int i;
int main()
{
    cout << "Enter the hieght ";
    cin >> hieght;
    int k = 0;
    for (int i = 1; i <= hieght; i++)
    {
        cout << setfill('*') << setw(hieght - ((i - 1) * 2 + 1) / 2);
        int k = 0;
        for (int j = 0; j < (i - 1) * 2 + 1; j++)
        {
            if (j < i)
            {
                k++;
                cout << k;
            }

            else
            {
                k--;
                cout << k;
            }
        }
        cout << setfill('*') << setw(hieght - ((i - 1) * 2 + 1) / 2);
        cout << "\n";
    }
    for (int i = hieght; i >= 1; i--)
    {
        cout << setfill('*') << setw(hieght - ((i - 1) * 2 + 1) / 2);
        k = 0;
        for (int j = 0; j < (i - 1) * 2 + 1; j++)
        {
            if (j < i)
            {
                k++;
                cout << k;
            }

            else
            {
                k--;
                cout << k;
            }
        }
        cout << setfill('*') << setw(hieght - ((i - 1) * 2 + 1) / 2);
        cout << "\n";
    }
}
