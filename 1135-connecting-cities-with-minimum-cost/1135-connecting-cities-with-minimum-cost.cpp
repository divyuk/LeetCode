#include <vector>
#include <queue>
#include <utility> // for pair

using namespace std;

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        // Define a pair for weight and node
        typedef pair<int, int> M;

        // Priority queue to store weight -- node
        priority_queue<M, vector<M>, greater<M>> pq;
        vector<bool> visited(n + 1, false);
        int ans = 0;

        // Start from city 1
        pq.push({0, 1});

        while (!pq.empty()) {
            int w = pq.top().first;
            int c = pq.top().second;
            pq.pop();

            if (!visited[c]) {
                ans += w;
                visited[c] = true;

                for (auto& it : connections) {
                    int node, weight;
                    if (it[0] == c) {
                        node = it[1];
                        weight = it[2];
                    } else if (it[1] == c) {
                        node = it[0];
                        weight = it[2];
                    } else {
                        continue; // Not a connection from this city
                    }

                    if (!visited[node]) {
                        pq.push({weight, node});
                    }
                }
            }
        }

        // Check if all cities are visited
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                return -1;
            }
        }

        return ans;
    }
};
