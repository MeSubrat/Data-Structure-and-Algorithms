class Solution {

public:
    int maxDistance(vector<vector<int>>& grid) {
        int maxD = INT_MIN;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        vector<vector<int>> dist(n, vector<int>(m,0));
        int delrow[] = {0,-1,0,1};
        int delcol[] = {-1,0,1,0};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            dist[row][col] = dis;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];

                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol]){
                    q.push({{nrow,ncol},dis+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxD = max(maxD,dist[i][j]);
            }
        }

        return maxD == 0 ? -1 : maxD;
    }
};