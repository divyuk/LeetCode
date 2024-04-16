class Solution {
public:
    int minSteps(int n) {
        int press =0, d =2;
        while(n>1){
            while(n%d == 0){
                press+=d;
                n/=d;
            }
            d++;
        }
        return press;
    }
};