class Solution {
public:
    int answer = 0;

    void maxRequest(vector<vector<int>>& requests, vector<int>& indegree, int n, int index, int count) {
        if (index == requests.size()) {
            // Check if all buildings have an in-degree of 0.
            for (int i = 0; i < n; i++) {
                if (indegree[i]) return;    
            }
            answer = max(answer, count);
            return;
        }
        
     
        indegree[requests[index][0]]--;
        indegree[requests[index][1]]++;
       
        maxRequest(requests, indegree, n, index + 1, count + 1);
        // Backtrack
        indegree[requests[index][0]]++;
        indegree[requests[index][1]]--;
        // Ignore this request 
        maxRequest(requests, indegree, n, index + 1, count);
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> indegree(n, 0);
        maxRequest(requests, indegree, n, 0, 0);
        return answer;
    }
};

// TC : O(2^M * N) M : Number of request, N is the number of Buildings.
// SC : O(N+M)