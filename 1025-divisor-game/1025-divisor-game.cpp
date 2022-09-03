class Solution {
public:
    int calc(int n){
        for (int i = 1; i < n; i++)
        {
            if(n%i==0){
                n = n-i;
                return n;
            }
        }
        return -1;
    }
    int check(int n){
        int n1 = calc(n);
        if(n1==-1)
            return 0;
        return n1;
    }
    bool divisorGame(int n) {
        while (1)
        {
            n = check(n);
            if(n==0)
                return false;
            n = check(n);
            if(n==0)
                return true;
        }
        
    }
};