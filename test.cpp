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
// void reverse(bitset<32> &b){
//     int n
// }

int main()
{
    string s = "hello world";
    // cout<<reverseWords(s);
    int n = 8;
    bitset<32> b(n);
    int highestBit = log2(n);
    // reverse()
    int i=0;int j=highestBit;
    while(i<j){
        int temp = b[i];
        b[i] = b[j];
        b[j] = temp;
        i++;
        j--;
    }
    for (int i = 0; i <= highestBit; i++)
    {
        cout << b[i] << " ";
    }
}