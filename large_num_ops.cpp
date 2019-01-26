/**
 * OOPs Lab 2019 4th SEM
 * NAME : Jayjeet Chakraborty (17CS8036)
 * ASSIGNMENT : Sum,Diff,Mult of Large Numbers
 * DATE : 25/01/2019
 */

#include <bits/stdc++.h>
#define int long long
using namespace std;

string find_sum(string s1, string s2)
{
    if (s1.length() > s2.length())
    {
        swap(s1, s2);
    }

    string res = "";
    int n1 = s1.length();
    int n2 = s2.length();

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    int carry = 0;
    for (int i = 0; i < n1; i++)
    {
        int sum = (s1[i] - '0') + (s2[i] - '0') + carry;
        res.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    for (int i = n1; i < n2; i++)
    {
        int sum = (s2[i] - '0') + carry;
        res.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry)
    {
        res.push_back(carry + '0');
    }

    reverse(res.begin(), res.end());
    return res;
}

string find_diff(string s1, string s2)
{
    if (s1.length() > s2.length())
    {
        swap(s1, s2);
    }

    string res = "";
    int n1 = s1.length();
    int n2 = s2.length();

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    int carry = 0;
    for (int i = 0; i < n1; i++)
    {
        if (s2[i] - '0' >= s1[i] - '0')
        {
            res.push_back(((s2[i] - '0') - (s1[i] - '0')) + '0');
        }
        else
        {
            int x = 10 + (s2[i] - '0');
            res.push_back((x - (s1[i] - '0') - carry) + '0');
            carry = x / 10;
        }
    }

    for (int i = n1; i < n2; i++)
    {
        if (s2[i] - '0' < carry)
        {
            res.push_back((10 + (s2[i] - '0') - carry) + '0');
            carry = (10 + (s2[i] - '0')) / 10;
        }
        else
        {
            res.push_back(((s2[i] - '0') - carry) + '0');
        }
    }

    reverse(res.begin(), res.end());
    return res;
}

string find_multiply(string s1, string s2)
{
    int i = s1.length() - 1;
    int j = s2.length() - 1;
    int carry = 0;
    string ans = "0";
    if (i < j)
    {
        swap(s1, s2);
        i = s1.length() - 1;
        j = s2.length() - 1;
    }

    for (int k = j; k >= 0; k--)
    {
        string temp_mul = "";
        for (int l = i; l >= 0; l--)
        {
            int elem = (s1[l] - '0') * (s1[k] - '0') + carry;
            if (elem >= 10)
            {
                carry = elem / 10;
                temp_mul = char(elem % 10 + '0') + temp_mul;
            }
            else
            {
                carry = 0;
                temp_mul = char(elem % 10 + '0') + temp_mul;
            }
        }

        if (carry != 0)
        {
            temp_mul = char(carry + '0') + temp_mul;
        }
        carry = 0;
        int zeros = j - k;

        while (zeros--)
        {
            temp_mul = temp_mul + "0";
        }
        ans = find_sum(temp_mul, ans);
    }

    return ans;
}

int32_t main()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    cout << find_sum(s1, s2) << endl;
    cout << find_diff(s1, s2) << endl;
    cout << find_multiply(s1, s2) << endl;
}
