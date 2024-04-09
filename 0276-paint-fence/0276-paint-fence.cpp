class Solution {
public:
    int f(int n , int k){
        if(n==0) return 0;
        if(n==1) return k;
        if(n==2 ) return k*k;
        
        return (k-1) * ( f(n-1 , k ) + f(n-2, k)   );
    }
    
    int numWays(int n, int k) {
        return f(n,k);
    }
};