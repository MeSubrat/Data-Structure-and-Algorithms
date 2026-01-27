#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(nums[i]);
        }

        int longest = 1;
        //Iterate through the set
        for (auto it : st)
        {
            /*
            If the element's previous element is not present then we'll check the length,
            or if present then we'll move
            */
            if (st.find(it - 1) == st.end())
            {
                int cnt = 0;
                int x = it;
                while (st.find(x) != st.end())
                {
                    x = x + 1;
                    cnt += 1;
                }
                //Finding longest sequence
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};   

int main()
{
}