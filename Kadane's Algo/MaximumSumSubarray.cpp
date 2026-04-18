#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[i] = x;
    }
    
    //Kadane's Algo
    int sum = arr[0];
    int maxSum = arr[0];
    int start = 0;int end = 0;int tempStart = 0;
    //Approach - 1
    // for(int i=1;i<n;i++){
    //     sum+=arr[i];
    //     if(maxSum < sum){
    //         maxSum = sum;
    //         start = tempStart;
    //         end = i;
    //     }
    //     if(sum<0) {
    //         sum = 0;
    //         tempStart = i+1;
    //     }
    // }
    //Approach - 2
    int currSum = 0;
    for(int i=1;i<n;i++){
        if(currSum + arr[i] < arr[i]){
            currSum = arr[i];
            tempStart = i;
        }else{
            currSum += arr[i];
        }
        
        
        if(currSum > maxSum ){
            maxSum = currSum;
            start = tempStart;
            end = i;
        }
    }
    cout << "Maximum Subarray: " << maxSum << ", Subarray: [";
    for (int i = start; i <= end; i++) {
        cout << arr[i];
        if (i < end) cout << ", ";
    }
    cout << "]";
}