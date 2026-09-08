class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &grid,vector<vector<int>> & vis){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        // cnt++;

        int delrow[] = {0, -1, 0, 1};
        int delcol[] = {-1, 0, 1, 0};
        for(int i=0;i<4;i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow, ncol, grid, vis);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1 && (i==0 || i==(n-1) || j==0 || j==(m-1))){
                    dfs(i,j,grid, vis);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && vis[i][j] != 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};