class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int next = 0;
        int maxi = 0;
        int prev;
        for(int i=0;i<gain.size();i++){
            prev = next;
            next = prev + gain[i];
            maxi = max(maxi, next);
        }
        return maxi;
    }
};