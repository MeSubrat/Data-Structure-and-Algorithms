class Solution {
public:
    bool checkString(string s) {
        int a = 0;
        bool foundB = false;
        for(char c : s){
            if(c == 'a' && foundB == true){
                return false;
            }
            else if(c=='b'){
                foundB = true;
            }
        }
        return true;
    }
};