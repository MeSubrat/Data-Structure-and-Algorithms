class Solution {
private:
    bool fun(int i, int j,vector<vector<char>>& grid, int balance, vector<vector<vector<int>>> &dp){
        int n = grid.size();//Row
        int m = grid[0].size(); //Col
        //Base Case
        //Out of bounds
        if(i>=n|| j>=m) return false;

        //Update Balance
        grid[i][j] == '(' ? balance++ : balance--;
        if(balance<0) return false;

        if(i==n-1 && j==m-1){
            // grid[i][j] == '(' ? balance++ : balance--;
            // if(balance<0) return false;
            // else if(balance==0) return true;
            return balance == 0;
        }
        
        if(dp[i][j][balance] != -1) return dp[i][j][balance];
        bool up = fun(i+1, j, grid, balance,dp);
        bool left = fun(i, j+1, grid, balance,dp);

        return dp[i][j][balance] = up||left;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();//ROW
        int m = grid[0].size(); //Col
        vector<vector<vector<int>>> dp(n, 
            vector<vector<int>>(m,
                vector<int>(n+m+1, -1)
            )
        );
        return fun(0, 0,grid,0,dp);
    }
};