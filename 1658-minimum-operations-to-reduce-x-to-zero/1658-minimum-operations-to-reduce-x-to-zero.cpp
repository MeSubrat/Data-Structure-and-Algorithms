class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int preSum = 0;
        for(auto it:nums){
            preSum += it;
        }
        int i=0;int j=0;
        int target = preSum - x;
        if(target < 0) return -1;
        int n = nums.size();
        int currSum = 0;

        int best = -1;
        while(j<n){
            currSum += nums[j];
            while(i<=j && currSum > target){
                currSum -= nums[i++];
            }
            if(currSum == target){
                best = max(best, j-i+1);
            }
            j++;
        }
        return best==-1 ? -1 : n-best;

    }
};