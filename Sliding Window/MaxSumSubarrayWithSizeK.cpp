class Solution
{
public:
    int maxSubarraySum(vector<int> &arr, int k)
    {
        // code here
        int n = arr.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        int maxSum = 0;
        for (r = 0; r < k; r++)
        {
            sum += arr[r];
        }
        r--;
        while (l <= n - k)
        {
            maxSum = max(sum, maxSum);
            sum -= arr[l];
            l++;
            r++;
            sum += arr[r];
        }
        return maxSum;
    }
};