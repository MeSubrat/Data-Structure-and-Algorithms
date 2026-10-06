class Solution {
public:
    int minAddToMakeValid(string s) {
        int openCnt = 0;
        int ans = 0;
        for(char ch : s){
            if(ch == '('){
                openCnt++;
            }
            else{
                if(openCnt)
                    openCnt--;
                else ans++;
            }
        }
        return ans + openCnt;
    }
};