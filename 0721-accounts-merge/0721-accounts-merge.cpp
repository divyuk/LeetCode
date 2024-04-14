class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i)  parent[i] = i; // each element is parent
        
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
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
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();
        unordered_map<string, int> emailToIndex;
        unordered_map<int, string> indexToName;
        vector<int> roots(n, -1);

        // Create Union-Find and map emails to indices
        UnionFind uf(n);
        
        for (int i = 0; i < n; ++i) {
            indexToName[i] = accounts[i][0]; // Map index to name
            for (int j = 1; j < accounts[i].size(); ++j) { //starting from 1 as skipping the name
                const string& email = accounts[i][j];
                if (emailToIndex.find(email) == emailToIndex.end()) // email dosent exist
                    emailToIndex[email] = i;
                else uf.unite(i, emailToIndex[email]); 
            }
        }
        
        // for(auto it :emailToIndex ){
        //     cout<<it.first << " " << it.second <<"\n";
        // }
          for(auto it :indexToName ){
            cout<<it.first << " " << it.second <<"\n";
        }      
        
        // Group accounts by their root
        unordered_map<int, vector<string>> mergedAccounts;
        for (const auto& [email, index] : emailToIndex) {
            int root = uf.find(index);
            mergedAccounts[root].push_back(email);
        }

        // Format merged accounts
        vector<vector<string>> result;
        for (auto& [root, emails] : mergedAccounts) {
            sort(emails.begin(), emails.end());
            string name = indexToName[root];
            vector<string> mergedAccount = {name};
            mergedAccount.insert(mergedAccount.end(), emails.begin(), emails.end());
            result.push_back(mergedAccount);
        }

        return result;
    }
};


