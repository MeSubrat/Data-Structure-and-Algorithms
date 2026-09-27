// class Solution {
// public:
//     string reverseParentheses(string s) {
//         int n = s.length();
//         stack<int> st;
//         string ans = "";
//         for(int i=0;i<s.length();i++){
//             if(s[i] == ')'){
//                 string temp = "";
//                 while(!st.empty() && st.top()!='('){
//                     temp+=st.top();
//                     st.pop();
//                 }
//                 if(!st.empty()) st.pop();
//                 for(auto it : temp){
//                     st.push(it);
//                 }
//             }
//             else{
//                 st.push(s[i]);
//             }
//         }
//         while(!st.empty()){
//             ans+=st.top();
//         }
//         reverse(begin(ans), end(ans));
//         return ans;
//     }
// };

class Solution{
    public:
    string reverseParentheses(string s){
        int n = s.length();
        stack<int> st;
        vector<int> pair(n);

        for(int i=0;i<n;i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                int j = st.top();
                st.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }
        //Second pass
        string res = "";
        for(int i = 0,direction = 1;i<n;i+=direction){
            if(s[i] == '(' || s[i]==')'){
                i = pair[i];
                direction = -direction;
            }
            else{
                res += s[i];
            }
        }
        return res;
    }
};