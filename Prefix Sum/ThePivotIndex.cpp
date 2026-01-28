#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        for (int el : nums)
        {
            sum += el;
        }
        int ls = 0, rs = sum;
        for (int i = 0; i < n; i++)
        {
            rs -= nums[i];
            if (ls == rs)
                return i;
            ls += nums[i];
        }
        return -1;
    }
};

int main()
{
}