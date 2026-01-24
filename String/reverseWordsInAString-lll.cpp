class Solution
{
public:
    string reverseWordsInString(string &s, int start, int end)
    {
        string temp = "";
        while (start <= end)
        {
            temp += s[end--];
        }
        return temp;
    }

    string reverseWords(string s)
    {
        string result = "";
        int start = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                result += reverseWordsInString(s, start, i - 1);
                result += ' ';
                start = i + 1;
            }
        }
        result += reverseWordsInString(s, start, s.length() - 1);
        return result;
    }
};