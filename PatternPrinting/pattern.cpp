#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // Pattern - 1
    //  for (int i = 0; i < n; i++)
    //  {
    //      for (int j = 0; j < n; j++)
    //      {
    //          cout << "*";
    //      }
    //      cout << endl;
    //  }

    // Pattern - 2
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

    // Pattern - 3
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout << j;
    //     }
    //     cout << endl;
    // }
    // Pattern - 4
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout << i;
    //     }
    //     cout << endl;
    // }
    // Pattern - 5
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n - i; j++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
    // Pattern - 6
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n - i+1; j++)
    //     {
    //         cout << j;
    //     }
    //     cout << endl;
    // }
    // Pattern - 7
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n - i; j++)
    //     {
    //         cout << " ";
    //     }
    //     for (int k = n - i + 1; k <= n + i - 1; k++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
    // Or
    // for (int i = 1; i <= n; i++)
    // {
    //     // spaces
    //     for (int j = 1; j <= n - i; j++)
    //         cout << " ";

    //     // stars (direct logic)
    //     for (int k = 1; k <= 2 * i - 1; k++)
    //         cout << "*";

    //     cout << endl;
    // }
    // Pattern - 8
    for (int i = 1; i <= n; i++)
    {
        // Space
        for (int k = 1; k <= i - 1; k++)
            cout << " ";
        // Stars
        for (int j = 1; j <= (2 * n - 2*i+1); j++)
            cout << "*";
        cout << endl;
    }
}