#include<bits/stdc++.h>

class Solution
{
public:
    int longestKSubstr(string &s, int k)
    {
        // code here
        unordered_map<char, int> mpp;
        int maxL = INT_MIN;

        int i = 0, j = 0;

        while (j < s.size())
        {
            mpp[s[j]]++;
            if (mpp.size() == k)
            {
                maxL = max(maxL, j - i + 1);
            }
            if (mpp.size() > k)
            {
                mpp[s[i]]--;
                if (mpp[s[i]] == 0)
                    mpp.erase(s[i]);
                i++;
            }
            j++;
        }
        return maxL == INT_MIN ? -1 : maxL;
    }
};