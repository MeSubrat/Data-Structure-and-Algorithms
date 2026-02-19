#include <bits/stdc++.h>
using namespace std;
// POTD : 19th Feb 2026
int countBinarySubstrings(string s)
{
    int prev = 0;
    int curr = 1;
    int result = 0;
    for (int i = 1; i < s.length(); i++)
    {

        if (s[i - 1] == s[i])
        {
            curr++;
        }
        else
        {

            result += min(curr, prev);
            prev = curr;
            curr = 1;
        }
        // cout << curr << " " << prev << endl;
    }
    return result + min(curr, prev);
}

int main()
{
    string s = "00110011";
    cout << countBinarySubstrings(s);
}