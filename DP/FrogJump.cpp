class Solution
{
public:
    int findCost(int n, vector<int> &height, vector<int> &dp)
    {
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int left = findCost(n - 1, height, dp) + abs(height[n - 1] - height[n]);
        int right = INT_MAX;
        if (n > 1)
            right = findCost(n - 2, height, dp) + abs(height[n] - height[n - 2]);

        return dp[n] = min(left, right);
    }
    int minCost(vector<int> &height)
    {
        // Code here
        int n = height.size() - 1;
        vector<int> dp(n + 1, -1);
        return findCost(n, height, dp);
    }
};