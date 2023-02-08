class Solution {
public:
    int findComplement(int num) {
        if(num==0) return 1;
        int num_bits = log2(num) +1;
        int mask = (unsigned)(1<<num_bits) - 1;
        return num^mask;
    }
};