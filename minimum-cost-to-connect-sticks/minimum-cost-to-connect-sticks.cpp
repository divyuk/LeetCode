class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int n = sticks.size();
        if(n==1) return 0;
        
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(int stick : sticks) pq.push(stick);
        
        int ans=0;
        while(pq.size()!=1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            int sum  = a+b;
            ans+=sum;
            pq.push(sum);
        }
        return ans;
    }
};