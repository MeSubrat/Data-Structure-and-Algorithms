class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
        for(int ind1=0;ind1<=n1;ind1++) dp[ind1][0] = 0;
        for(int ind2=0;ind2<=n2;ind2++) dp[0][ind2] = 0;

        for(int ind1=1;ind1<=n1;ind1++){
            for(int ind2=1;ind2<=n2;ind2++){
                if(text1[ind1-1] == text2[ind2-1])
                        dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                else dp[ind1][ind2] = max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
            }
        }
        int len = dp[n1][n2];

        string ans = "";
        int i= n1; int j=n2;
        while(i>0 && j>0){
            if(text1[i-1] == text2[j-1]){
                ans += text1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                ans += text1[i-1];
                i--;
            }
            else {
                ans += text2[j-1];  
                j--;
            }
        }
        while(i>0){
            ans += text1[i-1];
            i--;
        }
        while(j>0){
            ans+=text2[j-1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};