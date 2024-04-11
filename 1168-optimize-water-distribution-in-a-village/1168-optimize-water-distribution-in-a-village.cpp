class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        // min heap to maintain the order of edges to be visited.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> edgesHeap;

        // representation of graph in adjacency list
        vector<vector<pair<int, int>>> graph(n + 1);
        for (int i = 0; i <= n; ++i) {
            graph[i] = vector<pair<int, int>>();
        }

        // add a virtual vertex indexed with 0,
        //   then add an edge to each of the house weighted by the cost
        for (int i = 0; i < wells.size(); ++i) {
            pair<int, int> virtualEdge = make_pair(wells[i], i + 1);
            graph[0].push_back(virtualEdge);
            // initialize the heap with the edges from the virtual vertex.
            edgesHeap.push(virtualEdge);
        }

        // add the bidirectional edges to the graph
        for (int i = 0; i < pipes.size(); ++i) {
            int house1 = pipes[i][0];
            int house2 = pipes[i][1];
            int cost = pipes[i][2];
            graph[house1].push_back(make_pair(cost, house2));
            graph[house2].push_back(make_pair(cost, house1));
        }

        // kick off the exploration from the virtual vertex 0
        unordered_set<int> mstSet;
        mstSet.insert(0);

        int totalCost = 0;
        while (mstSet.size() < n + 1) {
            pair<int, int> edge = edgesHeap.top();
            edgesHeap.pop();
            int cost = edge.first;
            int nextHouse = edge.second;
            if (mstSet.find(nextHouse) != mstSet.end()) {
                continue;
            }

            // adding the new vertex into the set
            mstSet.insert(nextHouse);
            totalCost += cost;

            // expanding the candidates of edge to choose from in the next round
            for (pair<int, int> neighborEdge : graph[nextHouse]) {
                if (mstSet.find(neighborEdge.second) == mstSet.end()) {
                    edgesHeap.push(neighborEdge);
                }
            }
        }

        return totalCost;
    }
};
