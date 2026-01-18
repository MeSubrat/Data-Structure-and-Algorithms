class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0,r=0,maxLen=0, n=fruits.size();
        unordered_map<int,int> mpp;

        while(r<n){
            //Put the fruit into the basket by increasing the frequency
            mpp[fruits[r]]++;

            //Check for either size exceeds basket size or not
            if(mpp.size()>2){
                //Decrease the frequency
                mpp[fruits[l]]--;
                //If frequency becomes zero, erase the fruit from map
                if(mpp[fruits[l]]==0)mpp.erase(fruits[l]);
                l++; //Move left pointer
            }
            
            if(mpp.size()<=2){  //Everytime we'll check this window is valid or not!
                maxLen = max(maxLen,r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};