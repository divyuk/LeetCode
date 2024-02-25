class DisjointSet {
    public:
    vector<int> parent, size;
    int count;
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1);
        count = n;
        
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int findUPar(int node) {
        if(parent[node] == node) return node;
        
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if(ulp_u == ulp_v) return;
        
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        count--;
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        DisjointSet ds(n);
        unordered_map<int, int> mpp;

        for(int i = 0; i < n; i++) {
            int num = nums[i];
            for (int j = 2; j * j <= num; j++) {
                if (num % j == 0) {
                    if (mpp.find(j) != mpp.end()) {
                        ds.unionBySize(i, mpp[j]);
                    }
                    else {
                        mpp[j] = i;
                    }
                    while (num % j == 0) {
                        num /= j;
                    }
                }
            }
            if (num > 1) {
                if (mpp.find(num) != mpp.end()) {
                    ds.unionBySize(i, mpp[num]);
                }
                else mpp[num] = i;
            }
        }
        
        return ds.count == 1;
    }
};