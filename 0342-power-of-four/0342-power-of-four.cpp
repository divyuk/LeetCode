class Solution {
public:
    bool isPowerOfFour(int n) {
        while(n>1){
            if(n%4) return false;
                n/=4;
        }
        return n == 1;
        
        // Using bit manipulation
        // for(int i =0 ; i< 32 ; i+=2) if(n==1<<i) return true;
        // return false;
        
    }
};