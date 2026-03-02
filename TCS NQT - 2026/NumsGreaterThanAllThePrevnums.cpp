#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums[i] = x;
    }

    int greatest = nums[0];
    int cnt = 1;

    for (int i = 1; i < n; i++)
    {
        // cout << nums[i] << endl;
        if (nums[i] > greatest)
        {
            // cout << nums[i] << " > " << greatest << endl;
            greatest = nums[i];
            cnt++;
        }
    }
    cout << cnt;
}