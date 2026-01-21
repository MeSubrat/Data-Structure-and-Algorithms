class solution
{
public:
    int legthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mpp;
        int l = 0;
        int r = 0;
        int maxL = INT_MIN;
        if (s.length() < 1)
            return 0;
        if (s.length() == 1)
            return 1;
        while (r < s.length())
        {
            mpp[s[r]]++;

            if (mpp[s[r]] < 2)
            {
                maxL = max(maxL, r - l + 1);
            }
            else
            {
                while (mpp[s[r]] > 1)
                {
                    mpp[s[l]]--;
                    if (mpp[s[l]] == 0)
                        mpp.erase(s[l]);
                    l++;
                }
            }
            r++;
        }
        return maxL;
    }
};