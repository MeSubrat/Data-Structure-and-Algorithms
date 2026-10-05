class Solution {
private:
    int fun(int i, int j, string s1, string s2){
        // if(i<0) return j+1;
        // if(j<0) return i+1;
        //Shifting of Index
        if(i==0) return j;
        if(j==0) return i;

        if(s1[i-1] == s2[j-1]) return fun(i-1, j-1, s1, s2);
        int insertOp = 1 + fun(i, j-1, s1, s2);
        int deleteOp = 1 + fun(i-1, j, s1, s2);
        int replaceOp = 1 + fun(i-1, j-1, s1, s2);
        return min(insertOp, min(deleteOp, replaceOp));
    }
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length(); int n2 = word2.length();
        // return fun(n1, n2, word1, word2);
        //Tabulation
        vector<vector<int>> dp(n1+1, vector<int>(n2+1));
        for(int i=0;i<=n1;i++) dp[i][0] = i;
        for(int j=0;j<=n2;j++) dp[0][j] = j;

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else {
                    int insertOp = 1 + dp[i][j-1];
                    int deleteOp = 1 + dp[i-1][j];
                    int replaceOp = 1 + dp[i-1][j-1];
                    dp[i][j] = min(insertOp, min(deleteOp, replaceOp));
                }
            }
        }
        return dp[n1][n2];
    }
};