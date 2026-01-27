// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

// A shift on s consists of moving the leftmost character of s to the rightmost position.

// For example, if s = "abcde", then it will be "bcdea" after one shift.

// TC: O(N) SC: O(2*N);
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.length() != goal.length())
            return false;

        if ((s + s).find(goal) != string::npos)
            return true;
        return false;
    }
};

//TC: O(N^2) SC:(1);
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;

        for(int i=0;i<s.length();i++)
        {
            rotate(s.begin(),s.begin()+1,s.end());
            if(s==goal) return true;
        }
        return false;
    }
};