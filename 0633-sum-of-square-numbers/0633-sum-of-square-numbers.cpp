//T.C : O(sqrt(c))
//S.C : O(1)
class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0;
        long b = sqrt(c);

        while(a <= b) {
            long k = a*a + b*b;

            if(k < c) {
                a++;
            } else if (k > c) {
                b--;
            } else {
                return true;
            }
        }

        return false;
    }
};