class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n,0);

        dp[0] = 0;
        // dp[1] = 0;
        for(int i=1;i<n;i++){
            int minStep = INT_MAX;
            for(int j = 1;j<=k;j++){
                if(i-j >= 0){
                    int jump = dp[i-j] + abs(heights[i] - heights[i-j]);
                    minStep = min(jump, minStep);
                }
            }
            dp[i] = minStep;
        }
        return dp[n-1];
    }
};
