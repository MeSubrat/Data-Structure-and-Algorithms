// POTD : 18th Feb
class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        string binary = bitset<32>(n).to_string();
        binary = binary.substr(binary.find('1'));

        for (int i = 0; i < binary.length() - 1; i++)
        {
            if (binary[i] == binary[i + 1])
                return false;
        }
        return true;
    }
};