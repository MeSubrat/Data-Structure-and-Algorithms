#include <bits/stdc++.h>
using namespace std;

void reverseArr(vector<int> &nums, int start, int end)
{
    while (start <= end)
    {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int k = 3;
    reverseArr(arr, 0, arr.size() - 1);
    reverseArr(arr, 0, k - 1);
    reverseArr(arr, k, arr.size() - 1);

    for (int num : arr)
    {
        cout << num << " ";
    }
}