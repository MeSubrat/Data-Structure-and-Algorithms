class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        stack<int> st;
        st.push(0);
        for(char c : s){
            if(c=='(')
                // st.push(c);
                st.push(0);
            else{
                int score = st.top();
                st.pop();
                if(score == 0)
                    score = (1);
                else 
                    score *= 2;
                // st.push(score);
                st.top() += score;
            }
        }
        return st.top();
    }
};