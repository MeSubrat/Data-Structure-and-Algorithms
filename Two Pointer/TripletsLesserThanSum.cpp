class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        // Your code goes here
        int ans=0;
        // sort(begin(arr),end(end));
        sort(arr, arr + n);
        for(int i = 0 ;i<=n-3;i++){
            //Fix
            int fixed = arr[i];
            int l = i+1;
            int r = n-1;
            
            while(l < r){
                int newSum = fixed + arr[l] + arr[r];
                if(newSum < sum) {
                    ans+=(r-l);
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return ans;
    }
};