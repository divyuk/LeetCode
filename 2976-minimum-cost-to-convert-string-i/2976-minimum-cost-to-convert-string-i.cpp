class Solution {
public:
long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = 26;
        vector<vector<long long>> dist(n, vector<long long>(n, LLONG_MAX));

        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }

        for (int i = 0; i < original.size(); ++i) {
            int src = original[i] - 'a';
            int dst = changed[i] - 'a';
            int wt = cost[i];

            dist[src][dst] = min(dist[src][dst], static_cast<long long>(wt));
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long result = 0;
        for (int i = 0; i < source.length(); ++i) {
            int src = source[i] - 'a';
            int dest = target[i] - 'a';
            if (src == dest) {
                continue;
            }
            if (dist[src][dest] == LLONG_MAX) {
                return -1;
            } else {
                result += dist[src][dest];
            }
        }

        return result;
    }
};