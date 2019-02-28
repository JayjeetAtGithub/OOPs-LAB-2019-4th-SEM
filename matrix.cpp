#include <bits/stdc++.h>
using namespace std;

int32_t main(int32_t argc, char const *argv[])
{
    int m, n;
    cin >> n >> m;
    int **mat = new int *[n];
    for (int i = 0; i < n; i++)
    {
        *(mat + i) = new int[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    cout << "Upper Triangular Matrix\n";
    int upper_sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((m - i - 1) <= j)
            {
                upper_sum += *(*(mat + i) + j);
                cout << *(*(mat + i) + j) << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << "\n";
    }
    cout << "Upper Sum : " << upper_sum << "\n";

    cout << "Lower Triangluar Matrix\n";
    int lower_sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j <= (m - i - 1))
            {
                lower_sum += *(*(mat + i) + j);
                cout << *(*(mat + i) + j) << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << "\n";
    }

    cout << "Lower Sum : " << lower_sum << "\n";

    cout << "Sum of Lower and Upper Matrix : \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j <= (m - i - 1) && j >= (m - i - 1))
            {
                cout << *(*(mat + i) + j) * 2 << " ";
            }
            else if (j <= (m - i - 1))
            {
                cout << *(*(mat + i) + j) << " ";
            }
            else if (j >= (m - i - 1))
            {
                cout << *(*(mat + i) + j) << " ";
            }
                }
        cout << "\n";
    }

    return 0;
}
