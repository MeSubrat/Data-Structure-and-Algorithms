class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        if(k<=1) return 0;
        int l = 0;  int r = 0;
        int ans = 0;
        //Sort the array
        // sort(begin(nums),end(nums));
        long long prod = 1;
        while(r<n){
            //Calculate Product
            prod *= nums[r];

            //Shrink the window till product lesser or equal to k;
            while(prod>=k && l<=r){
                prod /= nums[l];
                l++;
            }
            
            if(prod < k){
                ans += (r-l+1);
                r++;
            }
        }
        return ans;
    }
};