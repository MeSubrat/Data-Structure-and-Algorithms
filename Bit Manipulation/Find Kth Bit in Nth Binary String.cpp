// O(2^N) - Solution
// class Solution
// {
// public:
//     string reverseString(string str)
//     {
//         int i = 0;
//         int j = str.length() - 1;
//         while (i < j)
//         {
//             swap(str[i], str[j]);
//             i++;
//             j--;
//         }
//         return str;
//     }
//     string invertString(string str)
//     {
//         for (int i = 0; i < str.length(); i++)
//         {
//             if (str[i] == '0')
//                 str[i] = '1';
//             else
//                 str[i] = '0';
//         }
//         return str;
//     }
//     string createString(string s, int n)
//     {
//         if (n == 1)
//             return "0";
//         string newStr = createString(s, n - 1);
//         string revAndinvStr = reverseString(invertString(newStr));
//         return newStr + "1" + revAndinvStr;
//     }
//     char findKthBit(int n, int k)
//     {
//         string str = createString("", n);
//         return str[k - 1];
//     }
// };

// Better Solution - O(n)
class Solution
{
public:
    char findKthBit(int n, int k)
    {
        if (n == 1)
            return '0';

        int len = (1 << n) - 1;  // 2^n - 1
        int mid = (len / 2) + 1; // middle position

        if (k == mid)
            return '1';
        else if (k < mid)
            return findKthBit(n - 1, k);
        else
        {
            char ch = findKthBit(n - 1, len - k + 1);
            return (ch == '0') ? '1' : '0';
        }
    }
};