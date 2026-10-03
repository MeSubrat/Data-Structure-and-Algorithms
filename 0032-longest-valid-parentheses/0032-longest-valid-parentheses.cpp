class Solution {

    
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        //left to right traverse
        int open = 0;int close = 0;
        int result = INT_MIN;
        for(int i=0;i<n;i++){
            s[i] == '(' ? open+=1 : close+=1;
            if(open == close)
                result = max(result, open+close);
            else if(close > open)
                open = close = 0;
        }   
        //Right to left 
        open = 0; close = 0;
        for(int i=n-1;i>=0;i--){
            s[i] == '(' ? open+=1 : close+=1;
            if(open == close)
                result = max(result, open+close);
            else if(close < open)
                open = close = 0;
        }
        return result == INT_MIN ? 0 : result;
    }
};