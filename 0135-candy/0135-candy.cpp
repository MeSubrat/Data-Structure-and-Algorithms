class Solution {
public:
    int candy(vector<int>& ratings) {
        //Better Approach O(2N), Space: O(N)
        // int n = ratings.size();
        // vector<int> left(n);
        // left[0] = 1;

        // for(int i=1;i<n;i++){
        //     if(ratings[i]>ratings[i-1]){
        //         left[i] = left[i-1] + 1;
        //     }
        //     else left[i] = 1;
        // }

        // int curr = 1; int right = 1; int sum = max(1, left[n-1]);
        // for(int i=n-2;i>=0;i--){
        //     if(ratings[i] > ratings[i+1]){
        //         curr = right + 1;
        //         right = curr;
        //     }
        //     else {
        //         curr = 1;
        //         right = 1;
        //     }
        //     sum += max(left[i],curr);
        // }
        // return sum;

        //Optimal Approach
        // int n = ratings.size();
        // int i=1;
        // int sum = 1;
        // while(i<n){
        //     if(ratings[i] == ratings[i-1]) {
        //         sum += 1;
        //         i++;
        //         continue;
        //     }
        //     // bool hasPeak = false;
        //     int peak = 1;
        //     while(i<n && ratings[i] > ratings[i-1]){
        //         peak += 1;
        //         sum += peak;
        //         // hasPeak = true;
        //         i++;
        //     }
        //     int down = 1;
        //     while(i<n && ratings[i] < ratings[i-1]){
        //         down += 1;
        //         sum += down;
        //         i++;
        //     }

        //     if( down > peak){
        //         sum += (down-peak);
        //     }
        // }
        // return sum;
        int n = ratings.size();
        if (n <= 1) return n;

        int sum = 1;
        int i = 1;
        
        while (i < n) {
            // 1. Handle flat ratings
            if (ratings[i] == ratings[i - 1]) {
                sum += 1;
                i++;
                continue;
            }

            // 2. Handle increasing slope (peak)
            int peak = 1;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak += 1;
                sum += peak;
                i++;
            }

            // 3. Handle decreasing slope (down)
            int down = 0;
            while (i < n && ratings[i] < ratings[i - 1]) {
                down += 1;
                sum += down;
                i++;
            }

            // 4. Correction if the down slope is longer than the peak
            // The peak element was counted in the rising sequence, but if the 
            // falling sequence is taller, the peak needs extra to satisfy both sides.
            if (down >= peak) {
                sum += (down - peak + 1);
            }
        }
        
        return sum;


    }
};