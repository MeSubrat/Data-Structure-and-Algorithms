/*
Problem Statement: Rearrange a given array such that the first half is arranged in increasing order, and the second half is arranged in decreasing order.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // [8 7 1 6 5 9]
    // cin >> n;
    vector<int> arr = {8, 7, 1, 6, 5, 9};
    int n = arr.size();

    sort(begin(arr), end(arr));

    reverse(arr.begin() + (n / 2), arr.end());

    for (auto it : arr)
    {
        cout << it << " ";
    }
}