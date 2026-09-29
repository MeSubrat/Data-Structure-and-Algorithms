class Solution {
private:
bool subsetSumToK(int n, int k, vector<int> &arr) {
    //Tabulation
    vector<int> prev(k+1, 0);
    prev[0] = 1;
    //Base
    for(int j=1;j<=k;j++){
        prev[j] = (arr[0] == j);
    }
    //Explore
    for(int i=1;i<n;i++){
        vector<int> curr(k+1,-1);
        for(int target=0;target<=k;target++){
            bool notTake = prev[target];
            bool take = false;
            if(target >= arr[i] && target-arr[i]>=0){
                take = prev[target-arr[i]];
            }
            curr[target] = (notTake||take);
        }
        prev = curr;
    }
    return prev[k];
}
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums){
            sum += num;
        }
        if(sum%2!=0) return false;
        return subsetSumToK(nums.size(), sum/2, nums);
    }
};