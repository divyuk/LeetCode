class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        vector<vector<int>> ans({intervals[0]});
        for (int i = 1; i < intervals.size(); i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int lastend = ans.back()[1];
            // Overlapping condition
            if(start<=lastend)
                ans.back()[1] = max(lastend,end);
            else
                ans.push_back({start,end});
        }
        return ans;
    }


};