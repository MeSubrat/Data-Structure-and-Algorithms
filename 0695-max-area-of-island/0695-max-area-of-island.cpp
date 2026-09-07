class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, int &cnt){
        // int area = 1;
        cnt++;
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow >= 0 && nrow < n &&
            ncol >= 0 && ncol < m &&
            grid[nrow][ncol] == 1 &&
            !vis[nrow][ncol]) {
                // area += dfs(nrow, ncol, vis, grid);
                dfs(nrow, ncol, vis, grid,cnt);
            }
        }
        // return area;

    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));
        int area = 0;
        int maxArea = 0;
        int cnt = 0;
        int maxCnt = 0;
        for(int row = 0;row<n;row++){
            for(int col = 0;col<m;col++){
                if(!vis[row][col] && grid[row][col] == 1){
                    // area = dfs(row, col, vis, grid);
                    cnt = 0;
                    dfs(row, col, vis, grid,cnt);
                    // maxArea = max(area, maxArea);
                }
                maxCnt = max(maxCnt,cnt);
            }
        }
        return maxCnt;
    }
};