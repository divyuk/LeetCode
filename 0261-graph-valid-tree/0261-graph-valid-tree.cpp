class DisjointSet{
private:
    vector<int>parent;
    vector<int>rank;
public:
    DisjointSet(int n ){
        parent.resize(n);
        rank.resize(n,0);
        for(int i =0;i<n;i++) parent[i]=i;
    }
    
    int find(int x){
        if(parent[x]!=x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void Union(int x, int  y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY) return;
        if(rank[rootX] < rank[rootY]) parent[rootX] = rootY;
        else if(rank[rootX] > rank[rootY]) parent[rootY] = rootX;
        else{
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false; // Check if number of edges is one less than number of nodes (required for a tree)

        DisjointSet ds(n);
        for (auto& edge : edges) {
            int x = edge[0];
            int y = edge[1];
            if (ds.find(x) == ds.find(y)) return false; // Check for cycles
            ds.Union(x, y);
        }

        // Check if all nodes are connected, i.e., they share the same root
        int root = ds.find(0);
        for (int i = 1; i < n; i++) {
            if (ds.find(i) != root) return false;
        }

        return true;
    }
};