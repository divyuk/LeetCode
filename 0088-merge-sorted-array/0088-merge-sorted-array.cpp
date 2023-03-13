class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int len1 = m+n;
        int y = m+n-1;
        int i = m-1;
        int j = n-1;
        int k = len1-1;
        while(j>=0){

            if(i>=0 and nums1[i]>nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        
            
        }
    }
};