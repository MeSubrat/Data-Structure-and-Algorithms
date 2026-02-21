#include <bits/stdc++.h>
using namespace std;
//POTD : 21-02-2026
bool isPrime(int n)
{
    if (n == 1 || n == 0)
        return false;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            cnt++;
    }
    if (cnt == 2)
        return true;
    return false;
}
int countPrimeSetBits(int left, int right)
{
    unordered_set<int> primeBits = {2,3,5,7,11,13,17,19,23,29,31};
    int count = 0;
    for (int i = left; i <= right; i++)
    {
        // if (isPrime(__builtin_popcount(i)) == true)
        // {
        //     cout << i << "->" << __builtin_popcount(i) << endl;
        //     count++;
        // }
        if(primeBits.find(__builtin_popcount(i)) != primeBits.end()) count++;
    }
    return count;
}

int main()
{
    cout << countPrimeSetBits(6, 10);
}