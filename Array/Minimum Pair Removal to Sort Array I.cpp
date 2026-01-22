class Solution {
public:
    int minPairSum(vector<int> &nums){
        int index = -1;
        int minSum = INT_MAX;
        // Find the index where the sum is minimum
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]+nums[i+1] < minSum )
            {
                index = i;
                minSum = nums[i] + nums[i+1];
            }
        }
        return index;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;
        while(!is_sorted(begin(nums),end(nums))){
            // Index Where the sum of two pair to be replaced
            int index = minPairSum(nums);

            //Replacement
            nums[index] = nums[index] + nums[index+1];

            //Erase the other element of the pair
            nums.erase(begin(nums)+index+1);

            //Increase nums count
            operations++;
        }
        return operations;
    }
};