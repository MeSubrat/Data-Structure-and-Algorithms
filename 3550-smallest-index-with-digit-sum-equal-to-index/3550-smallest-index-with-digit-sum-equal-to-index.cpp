class Solution {
private:
    bool check(int num, int index){
        int sum = 0;
        while(num>0){
            int digit = num % 10;
            sum += digit;
            num = num/10;
        }
        return sum == index;
    }
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(check(nums[i],i)) return i;
        }
        return -1;
    }
};