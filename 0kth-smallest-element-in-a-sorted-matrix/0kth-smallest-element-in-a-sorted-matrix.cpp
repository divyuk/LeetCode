class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>pq;
        int n = matrix.size();
        for(int i =0;i<n and k!=0; i++){
            for(int j=0;j<n;j++){
                pq.push(matrix[i][j]);
             
            }
        }
 // Pop elements from the heap until we reach the kth smallest element
        while (pq.size() > k) {
            cout<<pq.top()<<' ';
            pq.pop();
        }

        return pq.top();
    }
};
// 1 2
// 1 3