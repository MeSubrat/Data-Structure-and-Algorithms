// POTD : 25th Feb

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(__builtin_popcount(arr[j]) < __builtin_popcount(arr[i]) ) swap(arr[i],arr[j]);
                else if(__builtin_popcount(arr[j]) ==  __builtin_popcount(arr[i])) {
                    if(arr[j] < arr[i]) swap(arr[i],arr[j]);
                }
            }
        }
        return arr;
    }
};