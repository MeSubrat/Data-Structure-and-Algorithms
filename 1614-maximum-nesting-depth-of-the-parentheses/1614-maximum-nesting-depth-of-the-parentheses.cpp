class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int n = s.length();
        int maxDepth = INT_MIN;

        int depth = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                st.push(s[i]);
                depth++;
            }
            else if(s[i]==')'){
                if(!st.empty() && st.top() == '('){
                    maxDepth = max(depth, maxDepth);
                    st.pop();
                    depth--;
                }
            }
        }
        return maxDepth==INT_MIN ? 0 : maxDepth;

    }
};