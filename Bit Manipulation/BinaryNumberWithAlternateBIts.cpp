class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        // Approach - 1
        //  string binary = bitset<32>(n).to_string();
        //  binary = binary.substr(binary.find('1'));

        // for(int i=0;i<binary.length()-1;i++){
        //     if(binary[i] == binary[i+1]) return false;
        // }
        // return true;

        // Approach - 2
        //  bitset<32> b(n);
        //  int highestBit = log2(n); //Position where first 1 is present
        //  for(int i=0;i<=highestBit;i++){
        //      if(b[i] == b[i+1]) return false;
        //  }
        //  return true;

        // Approach - 3
        //  int currBit = n%2;
        //  n/=2;

        // while(n>0){
        //     if(currBit == n%2) return false;
        //     currBit = n%2;
        //     n/=2;
        // }
        // return true;

        // Approach - 4 : Constant Time
        unsigned int result = n ^ (n >> 1); // 1 0 1 0 ^ 0 1 0 1 (after right shift) = 1 1 1 1
        // But in case n = 8, it will also become 1111, so the below trick to be applied for correct result.
        return (result & (result + 1)) == 0; // Whether all bits are 1 or not to check this we use this trick.
    }
};