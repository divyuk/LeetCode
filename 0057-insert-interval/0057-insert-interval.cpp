class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& nI) {
        int n = intervals.size();
        vector<vector<int>>result;
        int i =0;
        
        while(i<n){
            
            if(intervals[i][1] < nI[0]) result.push_back(intervals[i]);
            
            else if(intervals[i][0] > nI[1] ) break;
                
            else{
                // merging
                nI[0] = min(intervals[i][0] , nI[0]);
                nI[1] = max(intervals[i][1] , nI[1]);
            }
            
            i++;
        }
        result.push_back(nI);
        while(i<n) {
            result.push_back(intervals[i]);
            i++;
        }
        
        return result;
        
    }
};