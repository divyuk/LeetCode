typedef pair<int,int>P; // capital , profit
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        int n = profits.size();
        vector<P>projects;
        
        for(int i =0;i<n; i++) projects.push_back({capital[i], profits[i]});
        
        sort(projects.begin(), projects.end());
        priority_queue<int>pq;
        int p =0;
        for(int i =0;i<k;i++){
            while(p<n and projects[p].first<=w)
                pq.push(projects[p++].second);
            if(pq.empty()) break;
            w+=pq.top();
            pq.pop();
        }    
        return w;
    }
};