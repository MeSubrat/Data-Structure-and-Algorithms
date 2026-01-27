/*
Given a string s, composed of different combinations of '(' , ')', '{', '}', '[', ']'. Determine whether the Expression is balanced or not.
An expression is balanced if:

Each opening bracket has a corresponding closing bracket of the same type.
Opening brackets must be closed in the correct order.
Examples :

Input: s = "[{()}]"
Output: true
Explanation: All the brackets are well-formed.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isBalanced(string &s)
    {
        // code here
        if (s.length() < 2)
            return false;
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            // Opening
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            // Closing
            else
            {
                if (st.empty())
                    return false;
                if ((s[i] == ')' && st.top() == '(') ||
                    (s[i] == '}' && st.top() == '{') ||
                    (s[i] == ']' && st.top() == '['))
                {
                    st.pop();
                }
                else
                {
                    return false; // For mimatch
                }
            }
        }

        return st.empty() ? true : false;
    }
};
int main()
{
}