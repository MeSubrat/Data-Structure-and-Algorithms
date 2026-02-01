#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumCost(vector<int> &nums)
    {
        // O(nlogn) O(1)
        // sort(nums.begin()+1,nums.end());
        // return nums[0] + nums[1] + nums[2];

        // O(n) O(1)
        int mini = INT_MAX;
        int sMini = INT_MAX;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < mini)
            {
                sMini = mini;
                mini = nums[i];
            }
            else if (nums[i] < sMini)
            {
                sMini = nums[i];
            }
        }
        return nums[0] + mini + sMini;
    }
};

int main()
{
}