class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Brute
        // unordered_map<int,int> mpp;
        // for(int item : nums){
        //     mpp[item]++;
        // }

        // for(auto it:mpp){
        //     if(it.second >= 2){
        //         return it.first;
        //     }
        // }
        // return 0;

        //OPTIMAL
        int slow = nums[0];
        int fast = nums[0];

        slow = nums[slow];
        fast = nums[nums[fast]];

        while(slow!=fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = nums[0];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;//Return fast.
    }
};