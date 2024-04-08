class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==0) return 1;
        sort(intervals.begin() , intervals.end());
        int prevEnd = intervals[0][1];
        for(int i = 1 ; i< intervals.size() ; i++){
            if(intervals[i][0] < prevEnd) return false;
            prevEnd = intervals[i][1];
        }
        return 1;
    }
};