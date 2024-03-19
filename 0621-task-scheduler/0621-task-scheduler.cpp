class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        int n=tasks.size();
        unordered_map<char,int>mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        priority_queue<int>pq;
        queue<pair<int,int>>q;
        for(auto it:mp){
            pq.push(it.second);
        }
        int time=0;
        while(!pq.empty() || !q.empty()){
            time++;
            if(!pq.empty()){
            int top=pq.top();
            pq.pop();
            if(top-1 !=0)
            q.push({top-1,time+k});
            }
            auto front=q.front();
            if(front.second==time){
                pq.push(front.first);
                q.pop();
            }
        }
        return time;
    }
};