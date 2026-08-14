class Solution {
public:
    int maximumLengthSubstring(string s) {
        //unordered_map<char,int> mpp;

        int i=0,j=0;
        int maxLen = INT_MIN;
        unordered_map<char,int> mpp;
        while(j<s.length()){
            mpp[s[j]]++;
            while(mpp[s[j]] > 2){
                mpp[s[i]]--;
                if(mpp[s[i]] == 0){
                    mpp.erase(s[i]);
                }
                i++;
            }
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};