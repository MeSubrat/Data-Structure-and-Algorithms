class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), left = 0;
        int maxKept = 0;

        for (int right = 0; right < n; right++) {
            while ((long long)nums[right] > (long long)nums[left] * k) {
                left++;
            }
            maxKept = max(maxKept, right - left + 1);
        }
        return n - maxKept;
    }
};