class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size();
        
        sort(points.begin() , points.end());
        int maxArea = 0;
        int x2 = points[n-1][0];
        for(int i = n-2; i>=0 ; i--){
            int difference = x2 - points[i][0];
            maxArea = max(maxArea, difference);
            x2 = points[i][0];
        }
        return maxArea;
    }
};