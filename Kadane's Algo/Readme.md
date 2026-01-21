## KADANE'S ALGORITHM
### Core intuition (very important 🧠)
- At every index, you ask just one question:
```
Is it better to extend the previous subarray or start a new one from here?
If your current sum becomes negative, it will only hurt future sums — so you drop it and start fresh.
```

### The idea in simple words

1. Keep a variable currentSum
2. Keep a variable maxSum
3. Traverse the array:
   - Add current element to currentSum
   - Update maxSum
   - If currentSum < 0, reset it to 0

### Sample Code(C++)
```
int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0];
    int currSum = 0;

    for (int i = 0; i < nums.size(); i++) {
        currSum += nums[i];
        maxSum = max(maxSum, currSum);

        if (currSum < 0) {
            currSum = 0;
        }
    }
    return maxSum;
}
```



##### NB: To execute this .md file, the shortcut is :
```
 ctrl + shift + v  
```