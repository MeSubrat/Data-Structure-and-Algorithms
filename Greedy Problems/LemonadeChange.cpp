#include <bits/stdc++.h>
using namespace std;

//Logic By me
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int fives = 0, tens = 0, twenties = 0;

        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 10)
            {
                tens++;
                if (fives < 1)
                    return false;
                fives--;
            }
            else if (bills[i] == 20)
            {
                twenties++;
                if (fives >= 1 && tens >= 1)
                {
                    tens--;
                    fives--;
                }
                else if (fives >= 3)
                {
                    fives -= 3;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                fives++;
            }
        }
        return true;
    }
};

int main()
{

}