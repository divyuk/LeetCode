class Solution {
public:
    bool f(int n){
        if(n==1) return false;
        for(int i =1 ; i<n ; i++ ){
            if(n%i==0){
                if(f(n-i)==false) return true;
            }
        }
        return false;
    }
    bool divisorGame(int n) {
        vector<int>dp(n+1,-1);
        // return f(n);
        return n%2==0;
    }
};