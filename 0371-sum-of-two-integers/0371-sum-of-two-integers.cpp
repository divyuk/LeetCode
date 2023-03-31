class Solution {
public:
    int getSum(int a, int b) {
  
        
        while(b!=0){
            unsigned int t = a;
            a = a^b;
            b= (t&b)<<1;
        }
        return a;
    }
};