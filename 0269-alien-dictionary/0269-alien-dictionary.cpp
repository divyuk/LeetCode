class Solution {
public:
    string alienOrder(vector<string>& words) {
        // Step 0: Create data structures and find all unique letters.
        unordered_map<char, vector<char>> adjList;
        unordered_map<char, int> counts; // this is indegree
        for (const string& word : words) {
            for (char c : word) {
                counts[c] = 0;
                adjList[c] = vector<char>();
            }
        }
        // Printing adjList
        cout << "Adjacency List:" << endl;
        for (const auto& pair : adjList) {
            cout << pair.first << ": ";
            for (char c : pair.second) {
                cout << c << " ";
            }
            cout << endl;
        }
        
        // Printing counts
        cout << "Counts:" << endl;
        for (const auto& pair : counts) {
            cout << pair.first << ": " << pair.second << endl;
        }
        
        // Step 1: Find all edges.
        for (int i = 0; i < words.size() - 1; i++) {
            const string& word1 = words[i];
            const string& word2 = words[i + 1];
            // Check that word2 is not a prefix of word1.
            if (word1.length() > word2.length() && word1.compare(0, word2.length(), word2) == 0) {
                return "";
            }
            // Find the first non-match and insert the corresponding relation.
            for (int j = 0; j < min(word1.length(), word2.length()); j++) {
                if (word1[j] != word2[j]) {
                    adjList[word1[j]].push_back(word2[j]);
                    counts[word2[j]]++;
                    break;
                }
            }
        }
        cout<<"----\n";
       // Printing adjList
        cout << "Adjacency List:" << endl;
        for (const auto& pair : adjList) {
            cout << pair.first << ": ";
            for (char c : pair.second) {
                cout << c << " ";
            }
            cout << endl;
        }
        
        // Printing counts
        cout << "Counts:" << endl;
        for (const auto& pair : counts) {
            cout << pair.first << ": " << pair.second << endl;
        }
        
        // Step 2: Breadth-first search.
        string result = "";
        queue<char> q;
        for (const auto& entry : counts) {
            if (entry.second == 0) {
                q.push(entry.first);
            }
        }
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            result += c;
            for (char next : adjList[c]) {
                counts[next]--;
                if (counts[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        if (result.size() < counts.size()) {
            return "";
        }
        return result;
    }
};
