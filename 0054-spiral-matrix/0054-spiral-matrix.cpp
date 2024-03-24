class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, bottom = matrix.size();
        int left = 0, right = matrix[0].size();
        vector<int>spiral;
        while(left <right and top<bottom){
            
            // left to right
            for(int i = left ;i<right ;i++) 
                spiral.push_back(matrix[top][i]);
            top++;
            
            // top to bottom
            for(int i=top;i<bottom;i++)
                spiral.push_back(matrix[i][right-1]);
            right--;
            
   // ! CASE FOR ONLY ROW MATRIX OR COLUMN MATRIX
            if(left>=right or top>=bottom)
                break;
            
            // right to left
            for(int i = right-1;i>=left;i--)
                spiral.push_back(matrix[bottom-1][i]);
            bottom--;
            
            // bottom to top
            for(int i = bottom-1;i>=top;i--)
                spiral.push_back(matrix[i][left]);
            left++;
            
        }
                
        return spiral;
    }
};