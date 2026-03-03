class Solution
{
public:
    string trimTrailingVowels(string s)
    {
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};

        while (s.length() != 0 && st.find(s[s.length() - 1]) != st.end())
        {
            s.pop_back();
        }
        return s;
    }
};