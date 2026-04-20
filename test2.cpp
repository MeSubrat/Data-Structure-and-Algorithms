#include <bits/stdc++.h>
using namespace std;
string compressString(string &s)
{
    int cnt = 1;
    string result = "";
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
            cnt++;
        else
        {
            result += s[i - 1] + to_string(cnt);
            cnt = 1;
        }
    }
    // last group
    result += s[s.length() - 1] + to_string(cnt);
    return result;
}
//Reverse words in a string
string reverseWords(string &s){
    vector<string> parts;
    reverse(s.begin(), s.end());    //i am subrat ->  tarbus ma i
    int start = 0;
    int i=0;
    while(i<s.length()){    
        if(s[i] == ' '){
            reverse(s.begin()+start, s.begin()+i);
            start = i+1;
        }
        i++;
    }
    //Last word
    reverse(s.begin()+start, s.begin()+s.length());
    return s;
}





int main()
{
    // string s;
    // getline(cin, s);
    // AABBAAC -> A2B2A2C1

    // cout << compressString(s);
    string s = "the sky is blue";
    cout<<reverseWords(s);
}