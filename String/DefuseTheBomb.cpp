class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n,0);
        if(k==0) return result;
        int l=-1,r=-1;
        if(k>0){
            l=1;
            r=k;
        }
        else{
            l=n-abs(k);
            r=n-1;
        }
        int windowSum = 0;
        //For initial sum
        for(int p=l;p<=r;p++){
            windowSum+=code[p];
        }
        for(int k=0;k<n;k++){
            result[k] = windowSum;
            //Remove the lth Element
            windowSum -= code[l%n];
            l++;
            //Add the rth element
            windowSum += code[(r+1)%n];
            r++;
        }
        return result;
    }
};