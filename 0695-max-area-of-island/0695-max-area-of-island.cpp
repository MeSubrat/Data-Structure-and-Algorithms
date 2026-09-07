class Solution {
private:
    int dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid){
        int area = 1;
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
                area += dfs(nrow, ncol, vis, grid);
            }
        }
        return area;

    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));
        int area = 0;
        int maxArea = 0;
        for(int row = 0;row<n;row++){
            for(int col = 0;col<m;col++){
                if(!vis[row][col] && grid[row][col] == 1){
                    // cnt++;
                    area = dfs(row, col, vis, grid);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};