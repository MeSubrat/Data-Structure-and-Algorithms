#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> s;
    s.insert(10);
    s.insert(20);
    s.erase(10);
    for (auto it : s)
    {
        cout << it;
    }
    cout<<s.size();
}