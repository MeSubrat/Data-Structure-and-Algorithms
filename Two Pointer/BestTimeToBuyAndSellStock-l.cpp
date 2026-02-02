#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int i = 0, j = 0;
        int n = prices.size();
        int maxProfit = INT_MIN;
        while (j < n)
        {
            if (prices[j] < prices[i])
                i++;
            else
            {
                int diff = prices[j] - prices[i];
                maxProfit = max(maxProfit, diff);
                j++;
            }
        }
        return maxProfit;
    }
};

int main()
{
}