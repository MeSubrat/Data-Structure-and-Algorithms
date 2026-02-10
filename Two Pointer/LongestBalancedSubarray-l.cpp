class Solution
{
public:
    int longestBalanced(vector<int> &nums)
    {
        int result = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            unordered_set<int> evenSet;
            unordered_set<int> oddSet;

            for (int j = i; j < nums.size(); j++)
            {
                if (nums[j] % 2 == 0)
                    evenSet.insert(nums[j]);
                else
                    oddSet.insert(nums[j]);

                if (evenSet.size() == oddSet.size())
                {
                    result = max(result, j - i + 1);
                }
            }
        }
        return result == INT_MIN ? 0 : result;
    }
};