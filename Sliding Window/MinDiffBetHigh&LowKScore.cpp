class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k == 1) return 0;
        sort(nums.begin(),nums.end());
        int res = INT_MAX;
        int l = 0,r = l+k-1;

        while(l <= nums.size()-k && r<nums.size()){
            int diff = nums[r] - nums[r-k+1];
            res = min(res,diff);
            r++;l++;
        }
        return res;
    }
};