//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        //MSB -> 2^n-1
        int score = pow(2, n-1) * m;

        for(int j = 1; j < n; j++) {

            int countSameBits = 0; //count of 1s
            for(int i = 0; i < m; i++) {
                if(grid[i][j] == grid[i][0]) {
                    countSameBits++;
                }
            }

            int countOnes  = countSameBits;
            int countZeros = m - countOnes;

            int ones = max(countOnes, countZeros);

            score += (pow(2, n-j-1) * ones);            

            

        }

        return score;
        
    }
};