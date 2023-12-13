
class Solution {
public:
    int numSpecial(std::vector<std::vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rowSum(m, 0);
        vector<int> colSum(n, 0);
        int count = 0;

        // First pass: Count the number of 1s in each row and each column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    rowSum[i]++;
                    colSum[j]++;
                }
            }
        }

        // Second pass: Check if the current element is the only 1 in its row and column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1 && rowSum[i] == 1 && colSum[j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};
