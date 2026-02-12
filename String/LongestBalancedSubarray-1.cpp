class Solution
{
public:
    int longestBalanced(string s)
    {
        int maxLen = INT_MIN;
        for (int i = 0; i < s.length(); i++)
        {
            int freq[26] = {0};
            for (int j = i; j < s.length(); j++)
            {
                int maxFreq = INT_MIN;
                int minFreq = INT_MAX;
                freq[s[j] - 'a']++;

                for (auto it : freq)
                {
                    if (it > 0)
                    {
                        maxFreq = max(maxFreq, it);
                        minFreq = min(minFreq, it);
                    }
                }
                if (maxFreq == minFreq)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen == INT_MIN ? 0 : maxLen;
    }
};