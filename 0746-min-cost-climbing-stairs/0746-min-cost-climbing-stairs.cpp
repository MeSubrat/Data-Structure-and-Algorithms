class Solution {
private:
    //Recursive Approach
    int fun(int ind, vector<int> &nums){
        if(ind == 0) return 0;
        if(ind == 1) return 0;

        int fs = fun(ind-1,nums) + nums[ind-1];
        int ss = INT_MAX;
        if(ind>1){
            ss = fun(ind-2,nums) + nums[ind-2];
        }
        return min(ss, fs);
    }
    int funMemo(int ind, vector<int> &nums,vector<int> &dp){
        if(ind==0 || ind==1) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int fs = funMemo(ind-1,nums,dp) + nums[ind-1];
        int ss = INT_MAX;
        if(ind>1){
            ss = funMemo(ind-2,nums,dp) + nums[ind-2];
        }
        return dp[ind] = min(ss, fs);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // return fun(n, cost);
        vector<int> dp(n+1,-1);
        return funMemo(n, cost, dp);
    }
};