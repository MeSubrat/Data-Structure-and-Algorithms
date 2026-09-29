class MemoSolution {
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

class Solution{
    public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();//ROW
        int m = grid[0].size(); //Col
        vector<vector<vector<int>>> dp(n, 
            vector<vector<int>>(m,
                vector<int>(n+m+1, -1)
            )
        );
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                for(int k=0;k<=(n+m-1);k++){
                    int newBalance = (grid[i][j]=='(') ? k+1 : k-1;
                    if(newBalance < 0 || newBalance > n+m-1){
                        dp[i][j][k] = false;
                        continue;
                    }
                    if(i==n-1 && j==m-1){
                        dp[i][j][k] = (newBalance==0);
                        continue;
                    }
                    
                    bool down = false;
                    if(i+1<n){
                        down = dp[i+1][j][newBalance];
                    }
                    bool right = false;
                    if(j+1 < m){
                        right = dp[i][j+1][newBalance];
                    }
                    dp[i][j][k] = (down||right);
                }
            }
        }
        return dp[0][0][0];
    }
};








