class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        set<int>r;
        vector<int>result;
        for(int i : nums1) s.insert(i);
        
        for(int i : nums2){
            if(s.find(i) != s.end() )
                r.insert(i);
       
        }
        for(int i : r) result.push_back(i);
        return result;
    }
};