class Solution
{
public:
    string reverseString(string str)
    {
        int i = 0;
        int j = str.length() - 1;
        while (i < j)
        {
            swap(str[i], str[j]);
            i++;
            j--;
        }
        return str;
    }
    string invertString(string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '0')
                str[i] = '1';
            else
                str[i] = '0';
        }
        return str;
    }
    string createString(string s, int n)
    {
        if (n == 1)
            return "0";
        string newStr = createString(s, n - 1);
        string revAndinvStr = reverseString(invertString(newStr));
        return newStr + "1" + revAndinvStr;
    }
    char findKthBit(int n, int k)
    {
        string str = createString("", n);
        return str[k - 1];
    }
};