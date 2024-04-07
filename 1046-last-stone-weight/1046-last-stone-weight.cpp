class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        if(stones.size()==1) return stones[0];
        for(int stone : stones){
            pq.push(stone);
        }
        while(!pq.empty()){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if(x!=y) pq.push(y-x);
            if(pq.size()==1) break;
        }
        return pq.size()==0 ? 0 : pq.top();
    }
};