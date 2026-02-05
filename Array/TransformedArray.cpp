
class Solution
{
public:
    vector<int> constructTransformedArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                int idx = (nums[i] + i) % n;
                result[i] = nums[idx];
            }
            else
            {
                int res = (-1 * nums[i]) % n;
                int idx = (i - res + n) % n;
                result[i] = nums[idx];
            }
        }
        return result;
    }
};