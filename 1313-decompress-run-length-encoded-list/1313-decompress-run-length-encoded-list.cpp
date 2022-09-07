class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int>ans;
        int i =0;
        int n = nums.size();
        while (i<n)
        {
            int freq = nums[i];
            int val = nums[i+1];
            for(int j = 0;j<freq;j++)
                ans.push_back(val);
            i=i+2;
        }
        return ans;
    }
};