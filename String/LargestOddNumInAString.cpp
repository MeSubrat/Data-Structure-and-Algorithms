class Solution {
public:
    string largestOddNumber(string num) {
        for(int i=num.length()-1;i>=0;i--){
            if((num[i]-'0')%2==1){ //nums[i] - '0' : It will give the integer value for the character.
                return num.substr(0,i+1); 
                // num.substr(index where the substring will start, length of the substring);
            }
        }
        return "";
    }
};