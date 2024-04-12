#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 1. Convert to adj
        unordered_map<int, vector<pair<int, int>>> adj;
        for (vector<int>& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int time = edge[2];
            adj[u].push_back({v, time});
        }

        // 2. Initialize result array
        vector<int> result(n + 1, -1);
        vector<bool> visited(n + 1, false);

        // 3. Min heap
        typedef pair<int, int> P;
        priority_queue<P, vector<P>, greater<P>> pq; // store time -> node
        pq.push({0, k});

        while (!pq.empty()) {
            int currTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            if (!visited[currNode]) {
                visited[currNode] = true;
                result[currNode] = currTime;

                for (pair<int, int>& next : adj[currNode]) {
                    int node = next.first;
                    int time = next.second;

                    if (!visited[node]) {
                        pq.push({currTime + time, node});
                    }
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (result[i] == -1) {
                return -1; // Some nodes are not reachable
            }
            maxTime = max(maxTime, result[i]);
        }

        return maxTime;
    }
};
