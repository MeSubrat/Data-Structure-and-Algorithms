class Solution {
private:
int fun(int ind, int target, vector<int> &coins, vector<vector<int>> &dp){
    if(ind == 0)
        return target % coins[0] == 0;
    if(dp[ind][target] != -1)
        return dp[ind][target];
    int notTake = fun(ind-1, target, coins, dp);
    int take = 0;
    if(target >= coins[ind])
        take = fun(ind, target - coins[ind], coins, dp);

    return dp[ind][target] = notTake + take;
}
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        return fun(n-1, amount, coins, dp);
    }
};