class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        for(int i=0;i<tasks.size();i++) tasks[i].push_back(i);// saving the index
        
        
        sort(tasks.begin(),tasks.end());// sorting based on task Number
        
        //Queue to select with lest processing time
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        long long  i=0, currTime=0;
        vector<int> ans;
        int n = tasks.size();
        while(i<n || !pq.empty()) {
            if(pq.empty() && currTime<tasks[i][0]) currTime=tasks[i][0];
            while(i<n && tasks[i][0]<=currTime) {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            cout<<currTime<<"\n";
            currTime+=pq.top().first;
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};