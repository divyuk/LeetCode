class UnionFind {
private:
    vector<int> parent;
    vector<double> weight;

public:
    UnionFind(int n) : parent(n), weight(n, 1.0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            int originalParent = parent[x];
            parent[x] = find(parent[x]);
            weight[x] *= weight[originalParent];
        }
        return parent[x];
    }

    void unite(int x, int y, double value) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;

        parent[rootX] = rootY;
        weight[rootX] = weight[y] * (value / weight[x]);
    }

    double query(int x, int y) {
        if (find(x) != find(y)) return -1.0;
        return weight[x] / weight[y];
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> variableToIndex;
        int index = 0;

        // Assign indices to variables
        for (const auto& equation : equations) {
            const string& var1 = equation[0];
            const string& var2 = equation[1];

            if (!variableToIndex.count(var1)) {
                variableToIndex[var1] = index++;
            }
            if (!variableToIndex.count(var2)) {
                variableToIndex[var2] = index++;
            }
        }

        UnionFind uf(index);

        // Populate the Union-Find with equations and values
        for (int i = 0; i < equations.size(); ++i) {
            const string& var1 = equations[i][0];
            const string& var2 = equations[i][1];
            double value = values[i];

            uf.unite(variableToIndex[var1], variableToIndex[var2], value);
        }

        vector<double> results;

        // Evaluate queries
        for (const auto& query : queries) {
            const string& start = query[0];
            const string& end = query[1];

            if (!variableToIndex.count(start) || !variableToIndex.count(end)) {
                results.push_back(-1.0);
                continue;
            }

            int indexStart = variableToIndex[start];
            int indexEnd = variableToIndex[end];

            results.push_back(uf.query(indexStart, indexEnd));
        }

        return results;
    }
};


