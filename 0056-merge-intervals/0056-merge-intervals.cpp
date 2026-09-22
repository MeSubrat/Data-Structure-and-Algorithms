class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int> &b){
            return a[0] < b[0];
        });
        if(intervals.size()<=1) return intervals;
        vector<int> freeItem = intervals[0];
        vector<vector<int>> res;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] <= freeItem[1]){
                freeItem[1] = max(intervals[i][1],freeItem[1]);
            }
            else{
                res.push_back(freeItem);
                freeItem = intervals[i];
            }
        }
        res.push_back(freeItem);
        return res;
    }
};