class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // string pref = strs[0];
        // int prefLen = pref.length();

        // for (int i = 1; i < strs.size(); i++) {
        //     string s = strs[i];
        //     while (prefLen > s.length() || pref != s.substr(0, prefLen)) {
        //         prefLen--;
        //         if (prefLen == 0) {
        //             return "";
        //         }
        //         pref = pref.substr(0, prefLen);
        //     }
        // }

        // return pref;  
        if(strs.size() == 1) return strs[0];      
        sort(strs.begin(),strs.end());
        string first = strs[0];
        string last = strs[strs.size()-1];
        string ans = "";
        for(int i=0;i<min(first.length(),last.length());i++){
            if(first[i] != last[i]) break;
            ans+=first[i];
        }
        return ans;
    }
};