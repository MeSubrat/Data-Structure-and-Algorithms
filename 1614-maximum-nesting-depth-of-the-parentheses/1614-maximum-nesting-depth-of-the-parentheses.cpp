class Solution {
public:
    int maxDepth(string s) {
        //TC : O(N)
        //SC : O(N)
        // stack<int> st;
        // int n = s.length();
        // int maxDepth = INT_MIN;

        // int depth = 0;
        // for(int i=0;i<n;i++){
        //     if(s[i] == '('){
        //         st.push(s[i]);
        //         depth++;
        //     }
        //     else if(s[i]==')'){
        //         if(!st.empty() && st.top() == '('){
        //             maxDepth = max(depth, maxDepth);
        //             st.pop();
        //             depth--;
        //         }
        //     }
        // }
        // return maxDepth==INT_MIN ? 0 : maxDepth;

        //TC : O(N)
        //SC : O(1)
        int n = s.length();
        int depth = 0;
        int maxDepth = INT_MIN;

        for(auto ch : s){
            if(ch == '(') depth++;
            else if(ch==')'){
                maxDepth = max(depth, maxDepth);
                depth--;
            }
        }
        return maxDepth==INT_MIN ? 0 : maxDepth;
    }
};