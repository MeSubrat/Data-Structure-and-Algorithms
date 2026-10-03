class Solution {
public:
    const int MOD = 1e9+7;
    int perfectSum(vector<int>& a, int target) {
        // code here
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        // return funMemo(n-1, target, arr, dp);
        //Tabulation
        //If num at index 0 == 0, then we have then 2 choices
        if(a[0] == 0)
            dp[0][0] = 2;
        else //if not then we have only that number to consider, so 1.
            dp[0][0] = 1;

        if(a[0] != 0 && a[0]<=target)
            dp[0][a[0]] = 1;//This means, index=0, target = a[0];

        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                int notPick = dp[i-1][j];
                int pick = 0;
                if(j >= a[i])
                    pick = dp[i-1][j - a[i]];
                
                dp[i][j] = (pick + notPick)%MOD;
            }
        }
        return dp[n-1][target];
    }
    int countPartitions(int n, int d, vector<int> &arr) {
        int totalSum = 0;
        for(auto& it : arr) totalSum += it;
        if(totalSum-d<0 || (totalSum-d) % 2) return 0;
        return perfectSum(arr, (totalSum-d)/2);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(), target, nums);
    }
};