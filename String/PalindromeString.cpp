class Solution {
  public:
    bool isPalindrome(string& s) {
        // code here
        int l=0,r=s.length()-1;
        
        while(l<=r && s[l] == s[r]){
            l++;
            r--;
        }
        return l>r?true : false;
    }
};