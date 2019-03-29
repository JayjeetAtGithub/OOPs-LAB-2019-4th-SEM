/**
 * OOPs Lab 2019 4th SEM
 * NAME : Jayjeet Chakraborty (17CS8036)
 * ASSIGNMENT : Indent a C file correctly
 * DATE : 25/01/2019
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    string name;
    name = argv[1];

    fstream file(name, ios::in);
    fstream test("test.txt", ios::out);
    int tabs = 0;
    if (file.is_open())
    {
        while (getline(file, str))
        {
            if (str[0] == '{')
            {
                for (int i = 1; i <= tabs; i++)
                    test << '\t';
                test << str << endl;
                tabs++;
            }
            else if (str[0] == '}')
            {
                tabs--;
                for (int i = 1; i <= tabs; i++)
                    test << '\t';
                test << str << endl;
            }
            else
            {
                for (int i = 1; i <= tabs; i++)
                    test << '\t';
                test << str << endl;
            }
        }
        file.close();
        test.close();
    }
    else
    {
        cout << "file not found" << endl;
    }
    return 0;
}
