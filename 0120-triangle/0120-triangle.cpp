class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n,0); //Represents the front row of current row, now here it base row
        //Base Case
        for(int col=0;col<n;col++){
            int row = n-1;
            front[col] = triangle[row][col];
        }
        //DP 
        for(int row=n-2;row>=0;row--){
            vector<int> curr(n,0); //Represents the current row
            for(int col=row;col>=0;col--){
                int down = front[col] + triangle[row][col];
                int diag = front[col+1] + triangle[row][col];

                curr[col] = min(down, diag);
            }
            front = curr;
        }
        return front[0];
    }
};