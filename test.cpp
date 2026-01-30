#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    string result = "";
    stack<string> st;
    int i = 0, j = 0;
    while (j < s.length())
    {
        while (s[j] == ' ' && j < s.length())
        {
            j++;
            i = j;
        }
        if (s[i] == ' ')
        {
            st.push(s.substr(i, i + j));
        }
        j++;
    }
    while (!st.empty())
    {
        string temp = st.top();
        result += temp + ' ';
        st.pop();
    }
    return result;
}

int main()
{
    string s = "hello world";
    cout<<reverseWords(s);
}