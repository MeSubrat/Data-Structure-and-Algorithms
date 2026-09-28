class MemoizationSolution {
    private:
    int fun(int i,int j, vector<vector<int>>& grid, vector<vector<int>> &dp){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return INT_MAX;
        if(dp[i][j] == -1) return dp[i][j];
        int up = INT_MAX;int down = INT_MAX;
        if(i>0){
            up = fun(i-1, j, grid,dp) + grid[i][j];
        }
        if(j>0){
            down = fun(i, j-1, grid,dp) + grid[i][j];
        }
        return dp[i][j] = min(up, down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,INT_MAX));
        return fun(m-1, n-1, grid,dp);
    }
};
//Tabulation tc: O(m*n) sc: O(m*n)
class TabSolution{
    public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,INT_MAX));
        
        // dp[0][0] = grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j] = grid[i][j];
                    continue;
                }
                else{
                    int up = INT_MAX;
                    int left = INT_MAX;
                    if(i>0){
                        up = dp[i-1][j] + grid[i][j];
                    }
                    if(j>0){
                        left = dp[i][j-1] + grid[i][j];
                    }
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};

//Space Optimised version
class Solution{
    public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n,INT_MAX));
        vector<int> prev(n,INT_MAX);
        for(int i=0;i<m;i++){
            vector<int> curr(n,INT_MAX);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    curr[j] = grid[i][j];
                    continue;
                }
                else{
                    int up = INT_MAX;
                    int left = INT_MAX;
                    if(i>0){
                        up = prev[j] + grid[i][j];
                    }
                    if(j>0){
                        left = curr[j-1] + grid[i][j];
                    }
                    curr[j] = min(up, left);
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};