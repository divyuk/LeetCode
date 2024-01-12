class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int m = a.size();
        int n = b.size();
        if(m>n) return findMedianSortedArrays(b,a); // First one to always sorter
        int low = 0, high = m;
        int total = m+n;
        int left = (m + n + 1)/2; // no of elements to pick from array
        while(low<=high){
            int mid1 = (low+high)>>1; // mid1 no of element to from arr1
            int mid2 = left-mid1; // remaining elemets from arr2
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX , r2 = INT_MAX;
            if(mid1<m) r1 = a[mid1];
            if(mid2<n) r2 = b[mid2];
            if(mid1-1>=0) l1 = a[mid1-1];
            if(mid2-1>=0)  l2 = b[mid2-1];
            
            if(l1<=r2 and l2<=r1){
                if(total%2==1) return max(l1,l2);
                else
                return ((double)(max(l1,l2) + min(r1,r2) )) /2.0;
            }
            else if(l1>r2) high = mid1-1;
            else 
                low = mid1+1;
        }
        return 0;
    }
};