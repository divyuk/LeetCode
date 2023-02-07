class Solution {
public:
    
    bool checkPrime(int n) 
    {
        if (n <= 1)  return false;
        if (n <= 3)  return true;

        if (n%2 == 0 || n%3 == 0) return false;

        for (int i=5; i*i<=n; i=i+6)
            if (n%i == 0 || n%(i+2) == 0)
               return false;

        return true;
    }

    int countPrimeSetBits(int left, int right) {
        // Count set bits
        int primeCount=0,n=0;
        while(left<=right){
            int c=0;
            n = left;
            while(n){
                n=n&(n-1);
                c++;
            }
            // Check if its prime
            if(checkPrime(c))
                primeCount++;
            left++;
        }
        return primeCount;
    }
};