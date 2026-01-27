#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n < 2 || k == 0)
            return false;
        bool ans = false;
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            // If element present
            if (mpp.find(nums[i]) != mpp.end())
            {
                if (abs(mpp[nums[i]] - i) <= k)
                    ans = true;
                else
                    mpp[nums[i]] = i;
            }
            // If element not present
            else
            {
                // Map index with corresponding element
                mpp[nums[i]] = i;
            }
        }
        return ans;
    }
};

int main()
{
}