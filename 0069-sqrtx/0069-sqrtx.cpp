class Solution {
public:
    int mySqrt(int x) {
        long long low =1,high=x,mid=0,res=0;
        while(low<=high){
            mid = low + (high-low)/2;
            if(mid*mid <= x){
                res= mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return (int)res;
    }
};