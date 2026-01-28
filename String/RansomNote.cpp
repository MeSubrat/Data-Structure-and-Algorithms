#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canConstruct(string r, string m)
    {
        int freq[26] = {0};
        if (m.length() < r.length())
            return false;

        unordered_map<char, int> mpp;
        for (char ch : m)
        {
            mpp[ch]++;
        }
        for (char ch : r)
        {
            if (mpp.find(ch) == mpp.end() || mpp[ch] <= 0)
                return false;
            mpp[ch]--;
        }
        return true;
    }
};

int main()
{
}