class Solution {
    private:
    int fun(int ind, vector<int> &nums, vector<int> &dp){
        if(ind == 0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind] != -1) return dp[ind];

        int notPick = fun(ind-1, nums, dp);
        int pick = nums[ind] + fun(ind-2,nums, dp);
        return dp[ind] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        // return fun(n-1, nums, dp);

        //Tabulation
        // dp[0] = nums[0];
        // int negative = 0;

        // for(int i=1;i<n;i++){
        //     int take = nums[i];
        //     if(i>1) take+= dp[i-2];
        //     int notTake = dp[i-1];
        //     dp[i] = max(take, notTake);
        // }
        // return dp[n-1];

        //Space optimisation
        int prev = nums[0];
        int prev2 = 0;

        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i>1) take += prev2;
            int notTake = prev;

            int curr = max(take, notTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};