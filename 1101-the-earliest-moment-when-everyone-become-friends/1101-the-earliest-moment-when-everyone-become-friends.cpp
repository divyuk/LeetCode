class Solution {
private:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());

        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;  // Each person is initially their own parent
        }

        int groups = n;
        for (const auto& log : logs) {
            int timestamp = log[0];
            int person1 = log[1];
            int person2 = log[2];

            if (find(person1) != find(person2)) {
                unite(person1, person2);
                groups--;
                if (groups == 1) { // Only one group left, all are friends
                    return timestamp;
                }
            }
        }

        return -1; // Not all became friends
    }
};
