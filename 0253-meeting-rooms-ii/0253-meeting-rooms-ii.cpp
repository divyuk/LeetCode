class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==0) return 1;
        sort(intervals.begin() , intervals.end());
        int prevEnd = intervals[0][1];
        int rooms=1;
        priority_queue<int, vector<int> , greater<int>>pq;
        pq.push(prevEnd);
        for(int i = 1 ; i<n; i++){
            if(intervals[i][0] < pq.top()) rooms++;
            else pq.pop();
            prevEnd = intervals[i][1];
            pq.push(prevEnd);
        }
        return rooms; 
    }
};