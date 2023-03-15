class Solution {
public:
    double calculationMachine(double x, int n){
        // Base Case
        if(x==0) return 0;
        if(n==0) return 1;

        double res = calculationMachine(x,n/2);
        res=res*res;
        return n%2?x*res:res;
    }
    double myPow(double x, int n) {
        //! Divide and Conquer Method
        double res = calculationMachine(x,abs(n));
        return n>=0 ? res : 1/res;
    }
};