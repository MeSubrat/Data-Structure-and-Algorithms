// class Solution {
// private:
// const int MOD = 1e9 + 7;
// int fun(int ind, int target, vector<int> &coins, vector<vector<int>> &dp){
//     if(ind == 0)
//         return target % coins[0] == 0;
//     if(dp[ind][target] != -1)
//         return dp[ind][target];
//     int notTake = fun(ind-1, target, coins, dp);
//     int take = 0;
//     if(target >= coins[ind])
//         take = fun(ind, target - coins[ind], coins, dp);

//     return dp[ind][target] = notTake + take;
// }
// public:
//     int change(int amount, vector<int>& coins) {
//         int n = coins.size();
//         // vector<vector<int>> dp(n, vector<int>(amount+1,-1));
//         // return fun(n-1, amount, coins, dp);

//         vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(amount+1,0));
//         //Base
//         for(int j=0;j<=amount;j++){
//             if(j % coins[0] == 0)
//                 dp[0][j] = 1;
//         }
//         //Explore
//         for(int i=1;i<n;i++){
//             for(int j=0;j<=amount;j++){
//                 int notTake = dp[i-1][j];
//                 int take = 0;
//                 if(j >= coins[i])
//                     take = dp[i][j - coins[i]];
//                 dp[i][j] = (notTake + take) ;
//             }
//         }
//         return dp[n-1][amount];
//     }
// };

class Solution{
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(amount + 1, 0));
        
        // Base case: for the first coin
        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0)
                dp[0][j] = 1;
        }
        
        // Explore
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                // Use unsigned long long here to prevent overflow during addition
                unsigned long long notTake = dp[i - 1][j];
                unsigned long long take = 0;
                
                if (j >= coins[i]) {
                    take = dp[i][j - coins[i]];
                }
                
                dp[i][j] = notTake + take;
            }
        }
        
        return dp[n - 1][amount];
    }
};