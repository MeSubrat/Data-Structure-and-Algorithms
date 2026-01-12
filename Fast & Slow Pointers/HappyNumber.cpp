class Solution
{
public:
    int next(int num)
    {
        int temp = num;
        int r, sum = 0;
        while (temp > 0)
        {
            r = temp % 10;
            r = r * r;
            sum = sum + r;
            temp = temp / 10;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        // unordered_set<int> seen;
        // int temp=n;
        // int r=0;
        // while(temp!=1 && seen.find(temp)==seen.end())
        // {
        //     int sum=0;
        //     seen.insert(temp);
        //     while(temp>0)
        //     {
        //         r=temp%10;
        //         r=r*r;
        //         sum=sum+r;
        //         temp=temp/10;
        //     }
        //     temp=sum;
        // }
        // return temp==1;
        int slow = n;
        int fast = next(n);

        while (fast != 1 && slow != fast)
        {
            slow = next(slow);
            fast = next(next(fast));
        }

        return fast == 1;
    }
};