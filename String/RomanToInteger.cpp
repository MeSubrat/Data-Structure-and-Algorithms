#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getValue(char ch)
    {
        switch (ch)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        }
        return 0;
    }
    int romanToInt(string s)
    {
        int result = 0;
        int curr = 0;
        int maxi = INT_MIN;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            curr = getValue(s[i]);

            if (curr >= maxi)
            {
                result += curr;
                maxi = curr;
            }
            else
            {
                result -= curr;
            }
        }
        return result;
    }
};

int main()
{
}