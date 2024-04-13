class Solution {
private:
    int maxHist(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();
        stack<pair<int,int>> stk; // index , height
        for (int i = 0; i < n; i++) {
            int start = i;
            while (!stk.empty() && stk.top().second > heights[i]) {
                int index = stk.top().first;
                int bigHeight = stk.top().second;
                stk.pop();
                maxArea = max(maxArea, bigHeight * (i - index));
                start = index;
            }
            stk.push({start, heights[i]});
        }
        while (!stk.empty()) {
            maxArea = max(maxArea , (n - stk.top().first) * stk.top().second);
            stk.pop();
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int r = matrix.size();
        int c = matrix[0].size();
        int maxArea = 0;
        vector<vector<int>> grid(r, vector<int>(c, 0));
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == '1') grid[i][j] = 1;
            }
        }
        
        vector<int> currRow = grid[0];
        int area = maxHist(currRow);
        maxArea = max(maxArea, area);
        
        for (int i = 1; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) currRow[j] += grid[i][j];
                else currRow[j] = 0;
            }
            area = maxHist(currRow);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};