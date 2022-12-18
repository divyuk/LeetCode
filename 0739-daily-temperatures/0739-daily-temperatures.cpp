class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>ans(n);
        stack<pair<int,int>>days;
        for (int i = 0; i < n; i++)
        {
            int currDay = i;
            int currTemp = temperatures[i];
            while(!days.empty() and days.top().second<currTemp ){
                int prevday = days.top().first;
                int prevTemp = days.top().second;
                days.pop();
                ans[prevday] = currDay - prevday;
            }
            days.push({currDay,currTemp});
        }
        
        return ans;
    }
};