class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        // first odd jump then alterating between even and odd jumps
        int n = A.size();
        vector<int> next_higher(n), next_lower(n);

        stack<int> stack1, stack2;
        vector<pair<int, int>> sortedA;
        
        for (int i = 0; i < n; i++) sortedA.push_back({A[i], i});
        

        sort(sortedA.begin(), sortedA.end());

        for (auto& p : sortedA) {
            int a = p.first, i = p.second;
            while (!stack1.empty() && stack1.top() < i) {
                next_higher[stack1.top()] = i;
                stack1.pop();
            }
            stack1.push(i);
        }

        sort(sortedA.begin(), sortedA.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first != b.first ? a.first > b.first : a.second < b.second;
        });

        for (auto& p : sortedA) {
            int a = p.first, i = p.second;
            while (!stack2.empty() && stack2.top() < i) {
                next_lower[stack2.top()] = i;
                stack2.pop();
            }
            stack2.push(i);
        }
        // for(int i=0;i<n;i++){
        //     cout<<next_lower[i]<<" ";
        // }

        vector<int> higher(n), lower(n);
        higher[n - 1] = lower[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            higher[i] = lower[next_higher[i]];
            lower[i] = higher[next_lower[i]];
        }
        
        int res = accumulate(higher.begin(), higher.end(), 0);
        return res;
    }
};