// #include <bits/stdc++.h>
// using namespace std;

// string reverseWords(string s)
// {
//     string result = "";
//     stack<string> st;
//     int i = 0, j = 0;
//     while (j < s.length())
//     {
//         while (s[j] == ' ' && j < s.length())
//         {
//             j++;
//             i = j;
//         }
//         if (s[i] == ' ')
//         {
//             st.push(s.substr(i, i + j));
//         }
//         j++;
//     }
//     while (!st.empty())
//     {
//         string temp = st.top();
//         result += temp + ' ';
//         st.pop();
//     }
//     return result;
// }
// // void reverse(bitset<32> &b){
// //     int n
// // }

// int main()
// {
//     string s = "hello world";
//     // cout<<reverseWords(s);
//     int n = 8;
//     bitset<32> b(n);
//     int highestBit = log2(n);
//     // reverse()
//     int i=0;int j=highestBit;
//     while(i<j){
//         int temp = b[i];
//         b[i] = b[j];
//         b[j] = temp;
//         i++;
//         j--;
//     }
//     for (int i = 0; i <= highestBit; i++)
//     {
//         cout << b[i] << " ";
//     }
// }

#include <bits/stdc++.h>
using namespace std;
string reverseString(string str)
{
    int i = 0;
    int j = str.length() - 1;
    while (i < j)
    {
        swap(str[i], str[j]);
        i++;
        j--;
    }
    return str;
}
string invertString(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '0')
            str[i] = '1';
        else
            str[i] = '0';
    }
    return str;
}
string createString(string s, int n)
{
    if (n == 1)
        return "0";
    // return createString(s,n-1) + "1" + reverseString(invertString(createString(s,n-1)));
    string newStr = createString(s, n - 1);
    string revAndinvStr = reverseString(invertString(newStr));
    return newStr + "1" + revAndinvStr;
}

int main()
{
    string s = "";
    string str = createString("", 3);
    cout<<str[0];
}