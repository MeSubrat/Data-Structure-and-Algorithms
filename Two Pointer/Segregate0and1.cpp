#include<bits/stdc++.h>

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int l = 0,r=arr.size()-1;
        while(l<r){
            if(arr[l] == 0) l++;
            else if(arr[r] == 1) r--;
            else{
                int k = arr[l];
                arr[l] = arr[r];
                arr[r] = k;
            }
        }
        
    }
};