#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];
            graph[u].push_back({v, p});
            graph[v].push_back({u, p});
        }

        vector<double> prob(n, 0.0);
        prob[start] = 1.0;

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});

        while (!pq.empty()) {
            auto [curProb, node] = pq.top();
            pq.pop();

            if (node == end) {
                return curProb;
            }

            for (auto [neighbor, edgeProb] : graph[node]) {
                double newProb = curProb * edgeProb;

                if (newProb > prob[neighbor]) {
                    prob[neighbor] = newProb;
                    pq.push({newProb, neighbor});
                }
            }
        }

        return 0.0;
    }
};
