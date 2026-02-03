#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isTrionic(vector<int> &nums)
    {
        int i = 0;
        int n = nums.size();

        // Inc
        while (i + 1 < n && nums[i] < nums[i + 1])
        {
            i++;
        }
        if (i == 0 || i == n - 1)
            return false;
        // Dec
        while (i + 1 < n && nums[i] > nums[i + 1])
            i++;
        if (i == n - 1)
            return false;

        // INC
        while (i + 1 < n && nums[i] < nums[i + 1])
            i++;
        if (i == n - 1)
            return true;
        return false;
    }
};

int main()
{
}