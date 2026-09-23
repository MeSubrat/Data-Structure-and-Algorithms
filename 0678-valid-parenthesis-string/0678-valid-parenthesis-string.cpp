class Solution {
    //Recursive Solution
private:
    bool fun(string s, int ind, int cnt){
        if(cnt<0) return false;
        if(ind == s.length()) return cnt==0;

        if(s[ind] == '(') return fun(s,ind+1,cnt+1);
        if(s[ind] == ')') return fun(s,ind+1,cnt-1);

        return fun(s,ind+1,cnt+1) || fun(s,ind+1,cnt) || fun(s,ind+1,cnt-1);
    }
public:
    bool checkValidString(string s) {
        //Recursive Solution
        // return fun(s, 0, 0);
        //Optimal Solution : Range based
        int min = 0;
        int max = 0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='(') {
                min+=1;
                max+=1;
            }
            else if(s[i] == ')'){
                min-=1;
                max-=1;
            }
            else{
                min -= 1;
                max += 1;
            }

            if(min < 0) min = 0;
            if(max < 0) return false;
        }
        return min == 0;
    }

};