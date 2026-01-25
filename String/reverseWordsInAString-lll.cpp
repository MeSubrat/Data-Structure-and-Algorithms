// O(n) TC, O(n) SC
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

// O(n) TC, O(1) SC
class Solution {
public:
    void reverseWordsInString(string &s, int start, int end) {
        while(start<=end){
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
        }
    }

    string reverseWords(string s) {
        string result ="";
        int start = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == ' '){
                int r = i-1;
                while(l<=r)
                {
                    char temp = s[l];
                    s[l] = s[r];
                    s[r] = temp;
                    l++;
                    r--;
                }
                start = i+1;
            }
        }
        int l = start;
        int r = s.length()-1;
        while(l<=r)
        {
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            l++;
            r--;
        }
        return s;
    }
};