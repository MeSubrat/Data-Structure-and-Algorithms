class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        if (nums.size() < 2)
            return 0;
        sort(nums.begin(), nums.end());

        int maxNum;
        int minNum;
        int maxLen = INT_MIN;
        int i = 0;
        int j = 0;

        while (j < nums.size())
        {
            minNum = nums[i];
            maxNum = nums[j];
            int diff = maxNum - minNum;

            if (diff > 1)
            {
                i++;
            }
            else if (diff == 1)
            {
                maxLen = max(maxLen, j - i + 1);
                j++;
            }
            else
            {
                j++;
            }
        }
        return maxLen == INT_MIN ? 0 : maxLen;
    }
};