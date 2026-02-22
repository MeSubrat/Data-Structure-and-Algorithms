#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {4, 5, 0, 1, 9, 0, 5, 0};
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     cin >> x;
    //     arr.push_back(x);
    // }
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {

        if (arr[i] == 0)
        {
            int j = i + 1;
            while (j < n && arr[j] == 0)
            {
                j++;
            }
            if (j < n)
                swap(arr[i], arr[j]);
            // j++;
        }
    }

    for (auto it : arr)
    {
        cout << it << " ";
    }
}