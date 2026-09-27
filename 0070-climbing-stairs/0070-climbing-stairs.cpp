class Solution {
private:
    //Recursive -> TLE
    int recFun(int n){
        if(n==0 || n==1) return 1;

        int left = recFun(n-1);
        int right = recFun(n-2);
        return left+right;
    }
    //Tabulation -> Accepted
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
        // vector<int> dp(n+1,-1);
        // return tabFun(n, dp);

        //Tabulation : Space O(N)
        vector<int> dp(n+1,-1);
        // dp[0] = 1;
        // dp[1] = 1;
        // for(int i=2;i<=n;i++){
        //     dp[i] = dp[i-1] + dp[i-2];
        // }
        // return dp[n];
        
        //Space O(1)
        int prev1 = 1;
        int prev2 = 1;

        for(int i=2;i<=n;i++){
            int x = prev1 + prev2;
            prev1 = prev2;
            prev2 = x;
        }
        return prev2;
    }
};