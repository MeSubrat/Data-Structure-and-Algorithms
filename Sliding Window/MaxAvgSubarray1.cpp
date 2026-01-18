class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg = 0;
        int sum = 0;  
        // Initial Window
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        avg = (double)sum/k;
        double maxAvg = avg;

        //Constant window traversal
        for(int i=k;i<nums.size();i++){
            sum+=nums[i];
            sum-=nums[i-k];
            avg = double(sum)/k;
            maxAvg = max(avg,maxAvg);
        }
        return maxAvg;
    }
};