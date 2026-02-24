/*
Constrains-
1<=N<=100
Example 1:
Input :
10  -> Integer
Output :
5 -> result- Integer
Explanation:
Binary representation of 10 is 1010. After toggling the bits(1010), will get 0101 which represents “5”. Hence output will print “5”.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    bitset<32> b(n);
    int highestBit = log2(n);

    for (int i = highestBit; i >= 0; i--)
    {
        cout << b[i];
    }
}