class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int arrows=1;
        
        sort(points.begin() , points.end());
        
        vector<int>prev = points[0];
        
        for(int i =1;i<points.size() ;i++ ){
            int currentStartingPoint = points[i][0];
            int currentEndingPoint = points[i][1];
            
            int previousStartingPoint = prev[0];
            int previousEndingPoint = prev[1];
            
            if(currentStartingPoint > previousEndingPoint ){
                arrows++;
                prev = points[i];
            }
            else{
                prev[0] = max(previousStartingPoint,currentStartingPoint);
                prev[1] = min(currentEndingPoint,previousEndingPoint );
            }
            
        }
        
        return arrows;
    }
};