class Solution {
public:
    int findCheapestPrice(int N, vector<vector<int>>& A, int S, int D, int K) {
        vector<pair<int,int>> adj[100];
        for(auto v : A) adj[v[0]].push_back({v[1], -v[2]});
        vector<int> visited(N, INT_MAX);
        priority_queue<tuple<int, int, int>> closest;
        
        closest.push(make_tuple(0, -1, S));

        while(!closest.empty()) {
            int dist, stops, cur;
            tie(dist, stops, cur) = closest.top(); closest.pop();
            
            if(stops>K or stops>=visited[cur]) continue;
            if(cur==D) return -dist;

            visited[cur] = stops;

            for(auto [neigh, weight] : adj[cur]) {
                closest.push(make_tuple(dist+weight, stops+1, neigh));
            }
        }
        return -1;
    }
};