// User function Template for C++

class Solution {
  public:
    int smallestSumSubarray(vector<int>& a) {
        // Code here
        int minSum = a[0];
        int sum = 0;
        
        for(int i=0;i<a.size();i++){
            sum+=a[i];
            
            minSum = min(minSum,sum);
            if(sum>0){
                sum = 0;
            }
        }
        return minSum;
    }
};
