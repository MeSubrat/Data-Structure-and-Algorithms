class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;
        
        // Count chars in s
        for (char c : s) {
            mp[c]++;
        }
        
        // Subtract and find the extra char in t
        for (char c : t) {
            if (mp[c] == 0) {
                return c;  // extra char found
            }
            mp[c]--;
        }
        
        return '\0';  // should never reach here
    }
};
