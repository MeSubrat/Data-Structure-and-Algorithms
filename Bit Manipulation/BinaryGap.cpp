//POTD : 22-02-2026
class Solution
{
public:
    int binaryGap(int n)
    {
        bitset<32> b(n);
        int highestBit = log2(n);

        // reverse
        int i = 0;
        int j = highestBit;
        while (i < j)
        {
            int temp = b[i];
            b[i] = b[j];
            b[j] = temp;
            i++;
            j--;
        }
        int start = 0;
        int len = 0;
        for (int i = 0; i <= highestBit; i++)
        {
            if (b[i] == 1)
            {
                len = max(len, (i - start));
                start = i;
            }
        }
        return len;
    }
};