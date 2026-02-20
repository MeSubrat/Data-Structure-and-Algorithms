#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &arr, int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void leftRotate(vector<int> &arr, int k)
{
    int n = arr.size();
    k = k % arr.size();
    if (k == 0)
        return;

    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
    reverse(arr, 0, n - 1);
}
void rightRotate(vector<int> &arr, int k)
{
    int n = arr.size();
    k = k % arr.size();
    if (k == 0)
        return;
    reverse(arr, 0, n-1);
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;
    leftRotate(arr, k);
    cout << "Left Rotation: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    // Reset array
    arr = {1, 2, 3, 4, 5};

    // Perform right rotation
    rightRotate(arr, k);
    cout << "Right Rotation: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}