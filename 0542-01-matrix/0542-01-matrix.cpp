class Solution {
private:
    void bfs(vector<vector<int>>& mat, vector<vector<int>>& res, vector<vector<int>>& vis,
    queue<pair<pair<int,int>,int>> &q){
        
        // q.push({{row, col},0});
        int delrow[] = {0,-1,0,1};
        int delcol[] = {-1, 0, 1, 0};
        int n = mat.size();
        int m = mat[0].size();

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            res[row][col] = dist;

            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && ncol>=0 && nrow<n&&ncol<m && !vis[nrow][ncol]){
                    q.push({{nrow,ncol},dist+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }


    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> res(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        bfs(mat,res, vis,q);

        return res;
    }
};