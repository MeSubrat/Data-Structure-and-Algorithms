#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        // Sort the array, cause the diff between adjacent elements will be minimum.
        sort(begin(arr), end(arr));

        // Find out the minimum difference
        int minDiff = INT_MAX;
        for (int i = 1; i < arr.size(); i++)
        {
            minDiff = min(minDiff, abs(arr[i] - arr[i - 1]));
        }

        // Find out the Adjacent pairs and store it in a vector.
        vector<vector<int>> result;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - arr[i - 1] == minDiff)
            {
                result.push_back({arr[i - 1], arr[i]});
            }
        }

        // Return answer
        return result;
    }
};

int main()
{
}