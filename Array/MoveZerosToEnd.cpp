#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int i = 0, j = 0;
        int n = nums.size();

        while (j < n)
        {
            if (nums[j] != 0)
            {
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
    }
};
int main()
{
    vector<int> arr = {0, 1, 0, 2, 3};
    Solution obj;
    obj.moveZeroes(arr);
    for(int num : arr){
        cout<<num <<" ";
    }
}