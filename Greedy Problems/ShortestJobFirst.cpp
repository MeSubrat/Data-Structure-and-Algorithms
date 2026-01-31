#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(vector<int> &bt)
    {
        // code here
        int timer = 0;
        int wt = 0;
        sort(begin(bt), end(bt));
        for (int i = 0; i < bt.size(); i++)
        {
            wt += timer;
            timer += bt[i];
        }
        return (wt / bt.size());
    }
};

int main()
{
}