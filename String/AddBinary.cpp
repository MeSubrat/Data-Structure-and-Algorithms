#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        int sum = 0;
        string res = "";

        while (i >= 0 || j >= 0 || carry)
        {
            sum = carry;
            if (i >= 0)
                sum += a[i--] - '0';
            if (j >= 0)
                sum += b[j--] - '0';

            res.push_back((sum % 2) + '0');
            carry = sum / 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
//POTD - 15th Feb - Solution Of CodeStoryWithMIK
class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int sum = 0;
        int i = a.length()-1;
        int j = b.length()-1;

        string result = "";

        while(i>=0 || j>=0){
            sum = carry;
            if(i>=0){
                sum += (a[i-- ] - '0');
            }
            if(j>=0){
                sum += (b[j--] - '0');
            }      
                
            result.push_back((sum%2 == 0) ? '0' : '1');
            carry = sum/2;
        }
        if(carry) result.push_back('1');
        reverse(result.begin(),result.end());
        return result;
    }
};

int main()
{
}