class Solution {
private:
int longestCommonSubsequence(string text1, string text2) {
    int n1 = text1.length();
    int n2 = text2.length();

    //Space Optimised
    vector<int>prev(n2+1,0), curr(n2+1, 0);
    //Base case
    for(int ind2=0;ind2<=n2;ind2++) prev[ind2] = 0;
    for(int ind1=1;ind1<=n1;ind1++){
        for(int ind2=1;ind2<=n2;ind2++){
            if(text1[ind1-1] == text2[ind2-1])
                    curr[ind2] = 1 + prev[ind2-1];
            else curr[ind2] = max(prev[ind2], curr[ind2-1]);
        }
        prev = curr;
    }
    return prev[n2];
}
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();int m = word2.length();
        int lcs = longestCommonSubsequence(word1, word2);
        return n-lcs + m-lcs;
    }
};