class Solution {
int fun(int ind, int tar, vector<int> &coins, vector<vector<int>> &dp){
    if(ind == 0){
        if(tar % coins[ind] == 0){
            return tar/coins[ind];
        } 
        return 1e9;
    }
    if(dp[ind][tar]!=-1) return dp[ind][tar];
        
    int notTake = 0 + fun(ind-1, tar, coins, dp);
    int take = 1e9;
    if(tar>=coins[ind])
        take = 1 + fun(ind, tar - coins[ind], coins, dp);

    return min(take, notTake);
}
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // int ans = fun(n-1, amount, coins, dp);
        // if(ans == 1e9)
        //     return -1;

        // return ans;

        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        //Base
        for(int j=1;j<=amount;j++){
            if(j % coins[0] == 0){
                dp[0][j] = j/coins[0];
            }
            else dp[0][j] = 1e9; 
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int notTake = 0 + dp[i-1][j];
                int take = 1e9;
                if(j>=coins[i])
                    take = 1 + dp[i][j - coins[i]];
                dp[i][j] = min(take, notTake);
            }
        }
        int ans = dp[n-1][amount];
        if(ans >= 1e9)
            return -1;
        return ans;
    }
};