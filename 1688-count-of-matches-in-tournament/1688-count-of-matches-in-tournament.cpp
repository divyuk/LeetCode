class Solution {
public:
    int numberOfMatches(int n) {
        int sum =0;
        int match=0;
        while(n!=1){
            if(n%2==0)
                match = n/2;
            else
                match = (n-1)/2;
            
            n = n - match;
            sum+=match;
        }
        return sum;
    }
};