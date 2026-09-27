class Solution {
private:
    int recFun(int n){
        if(n==0 || n==1) return 1;

        int left = recFun(n-1);
        int right = recFun(n-2);
        return left+right;
    }
    //Tabulation
    int tabFun(int n, vector<int> &dp){
        if(n == 0 || n==1) return 1;
        if(dp[n] != -1) return dp[n];
        int left = tabFun(n-1,dp);
        int right = tabFun(n-2,dp);

        dp[n] = left+right;
        return dp[n];
    }
public:
    int climbStairs(int n) {
        // return recFun(n);
        vector<int> dp(n+1,-1);
        return tabFun(n, dp);
    }
};