class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        int n=tasks.size();
        unordered_map<char,int>mp;
        // Put the count in map
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        priority_queue<int>pq;
        queue<pair<int,int>>q;
        
        // Put it in maxheap
        for(auto it:mp){
            pq.push(it.second);
        }
        int time=0;
        // Start processing
        while(!pq.empty() || !q.empty()){
            time++;
            if(!pq.empty()){
                int top=pq.top();
                pq.pop();
                if(top-1 !=0) // decrement the count as its processed and check if its
                    // not zero, if its zero no need to process it.
                    q.push({top-1,time+k});
            }
            auto front=q.front();
            // if its now time to process it put in maxheap and process it.
            if(front.second==time){
                pq.push(front.first);
                q.pop();
            }
        }
        return time;
    }
};

// TC : O(n*k) k is idle time , processing queue is O(log26)