class Solution {
public:
    int trap(vector<int>& A) {
        int n = A.size();
        int total_water=0;
        vector<int>left_barrier(n,0);
        vector<int>right_barrier(n,0);
        for(int i=1;i<n;i++)
            left_barrier[i] = max(left_barrier[i-1],A[i-1]);
        
        for(int i=n-2;i>=0;i--)
            right_barrier[i] = max(right_barrier[i+1],A[i+1]);
        
        for(int i =0;i<n;i++)
            total_water+=max(0,min(left_barrier[i],right_barrier[i]) -A[i] );

        return total_water;
    }
};