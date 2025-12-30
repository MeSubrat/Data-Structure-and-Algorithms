#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        for (int i = 0; word[i] != '\0'; i++)
        {
            if (word[i] == ch)
            {
                cout << "Here"<<endl;
                int l = 0, r = i;
                // reverse
                while (r > l)
                {
                    cout<<r<<" "<<l<<" "<<endl;
                    char temp = word[r];
                    word[r] = word[l];
                    word[l] = temp;
                    l++;
                    r--;
                }
                // Return word
                return word;
            }
        }
        return word;
    }
};

int main()
{
    string word = "abcdefd";
    char ch = 'd';
    Solution s;
    string result = s.reversePrefix(word, ch);
    cout << result << " ";
}