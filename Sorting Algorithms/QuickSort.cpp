#include <bits/stdc++.h>
using namespace std;

int getPartitionIdx(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int left = low;
    int right = high;

    while (left < right)
    {
        while (left <= high && arr[left] <= pivot)
            left++;
        while (right > low && arr[right] > pivot)
            right--;
        if (left < right)
            swap(arr[left], arr[right]);
    }
    swap(arr[low], arr[right]);
    return right;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if(low>=high) return; //Base case is important!
    int partitionIdx = getPartitionIdx(arr, low, high);
    quickSort(arr, low, partitionIdx-1);
    quickSort(arr, partitionIdx + 1, high);
}

int main()
{
    vector<int> arr = {5, 2, 3, 4, 6, 7};
    quickSort(arr, 0, arr.size() - 1);
    for (int num : arr)
    {
        cout << num << " ";
    }
}