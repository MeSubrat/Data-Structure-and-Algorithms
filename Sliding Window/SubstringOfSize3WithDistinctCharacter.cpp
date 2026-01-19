class Solution
{
public:
    int countGoodSubstrings(string s)
    {
        int i = 0;
        int j = 0;
        unordered_map<char, int> mpp;
        int count = 0;

        for (j = 0; j < 3; j++)
        {
            mpp[s[j]]++;
        }
        if (mpp.size() == 3)
            count++;
        mpp[s[i]]--;
        if (mpp[s[i]] == 0)
            mpp.erase(s[i]);
        i++;

        while (j < s.length())
        {
            mpp[s[j]]++;
            if (mpp.size() == 3)
                count++;
            mpp[s[i]]--;
            if (mpp[s[i]] == 0)
                mpp.erase(s[i]);
            i++;
            j++;
        }
        return count;
    }
};