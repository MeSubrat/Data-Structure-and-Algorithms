class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<3) return 0;

        //Sort
        sort(begin(nums),end(nums)); 

        // Fix one num
        int sum = 0, left = 0;
        int result = 0;
        int distance = INT_MAX;
        for(int i = 0 ; i<=n-3;i++){
            int right = n-1;
            int fix = nums[i];
            left = i+1;

            while(left<right){
                sum = fix + nums[left] + nums[right];
                int newDistance = abs(sum-target);

                if(newDistance < distance){
                    result = sum;
                    distance = newDistance;
                }

                if(sum > target) right--;
                else if(sum < target) left++;
                else return sum; // perfect closest
            }
        }
        return result;
    }
};