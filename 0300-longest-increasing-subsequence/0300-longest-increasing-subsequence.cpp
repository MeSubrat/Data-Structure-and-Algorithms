class Solution {
private:
    int fun(int ind, int prev, vector<int>& nums, vector<vector<int>> &dp)
    {
        //Base
        int n = nums.size();
        if(ind == n)
            return 0;
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        //Explore
        int notTake = 0 + fun(ind+1, prev, nums, dp);
        int take = 0;
        if(prev == -1 || nums[ind] > nums[prev]){
            take = 1 + fun(ind + 1, ind, nums, dp);
        }
        return dp[ind][prev+1] = max(take,notTake);
        
    }
public:

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return fun(0, -1, nums, dp);
        //Tabulation
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i=n-1;i>=0;i--){
            for(int prev = 0;prev<=n;prev++){
                int notTake = 0 + dp[i+1][prev];
                int take = 0;
                if(prev == 0 || nums[i] > nums[prev-1]){
                    take = 1 + dp[i + 1][i+1];
                }
                dp[i][prev] = max(take,notTake);
            }
        }
        return dp[0][0];
    }
};