class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        set<pair<int, int>> st;
        int i = 0, j = 0;

        while (j < s.length())
        {
            if (s[j] == '1')
            {
                i = j;
                while (j < s.length() && s[j] != '0')
                    j++;
                st.insert({j - 1, i});
            }
            j++;
        }
        return st.size() == 1 ? true : false;
    }
};

// BEST SOLUTION
for (int i = 1; i < s.length(); i++)
{
    if (s[i] == '1' && s[i - 1] == '0')
        return false;
}
return true;