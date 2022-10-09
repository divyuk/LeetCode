class Solution {
public:
    int subtractProductAndSum(int n) {
        int temp = n;
        int sum = 0, product =1, last=0;
        while(temp!=0){
            last= temp%10;
            sum+=last;
            product*=last;
            temp/=10;
        }
        return product - sum;
    }
};