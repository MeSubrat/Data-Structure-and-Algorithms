#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> sTot;
        unordered_map<char, char> tTos;
        for (int i = 0; i < s.length(); i++)
        {
            // S->T map
            // Character present
            if (sTot.find(s[i]) != sTot.end())
            {
                if (sTot[s[i]] != t[i])
                {
                    return false;
                }
            }
            // Character not present
            else
            {
                sTot[s[i]] = t[i];
            }

            // T -> S map
            // Character present
            if (tTos.find(t[i]) != tTos.end())
            {
                if (tTos[t[i]] != s[i])
                {
                    return false;
                }
            }
            // Character not present
            else
            {
                tTos[t[i]] = s[i];
            }
        }
        return true;
    }
};

int main()
{
}