#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr;
    int n;
    // cout<<"Enter the length: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        // cout<<"Enter "<<i<<"th element: ";
        cin >> x;
        arr.push_back(x);
        cout<<endl;
    }
    // Count Frequency
    map<int,int> freq;
    for (int &it : arr)
    {
        freq[it]++;
    }

    for (auto it:freq)
    {
        cout << it.first << " " << it.second << endl;
    }
}