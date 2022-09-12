class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int>start;
        vector<int>end1;
        for(int i =0;i<n;i++){
            start.push_back(intervals[i][0]);
            end1.push_back(intervals[i][1]);
        }
        sort(start.begin(),start.end());
        sort(end1.begin(),end1.end());
        int interval=1,j=0,i=1,ans=1;
        while(i<n and j<n){
            if(start[i]<=end1[j]){
                interval++;
                i++;
            }
            else{
                interval--;
                j++;
            }
            ans = max(ans,interval);
        }
        return ans;
    }
};