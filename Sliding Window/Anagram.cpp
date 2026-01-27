// Given two non-empty strings s1 and s2, consisting only of lowercase English letters, determine whether they are anagrams of each other or not.
// Two strings are considered anagrams if they contain the same characters with exactly the same frequencies, regardless of their order.

// Examples:

// Input: s1 = "geeks" s2 = "kseeg"
// Output: true 
// Explanation: Both the string have same characters with same frequency. So, they are anagrams.
// Input: s1 = "allergy", s2 = "allergyy" 
// Output: false 
// Explanation: Although the characters are mostly the same, s2 contains an extra 'y' character. Since the frequency of characters differs, the strings are not anagrams. 
// Input: s1 = "listen", s2 = "lists" 
// Output: false 
// Explanation: The characters in the two strings are not the same — some are missing or extra. So, they are not anagrams.

class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // code here
        int m = s1.length();
        int n = s2.length();
        
        if(m != n) return false;
        
        unordered_map<char,int> mpp1;
        unordered_map<char,int> mpp2;
        for(int i=0;i<m;i++)
        {
            mpp1[s1[i]]++;
            mpp2[s2[i]]++;
        }
        
        for(int i=0;i<m;i++)
        {
            char ch = s1[i];
            if(mpp1[ch] != mpp2[ch]) return false;
        }
        return true;
        
    }
};

//Optimised(Cleaner version)
class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // code here
        int m = s1.length();
        int n = s2.length();
        
        if(m != n) return false;
        
        int freq[26] = {0};
        for(int i=0;i<m;i++)
        {
            freq[s1[i] - 'a'] ++;
            freq[s2[i] - 'a'] --;
        }
        
        for(int i=0;i<26;i++)
        {
            if(freq[i] !=0 ) return false;
        }
        return true;
        
    }
};