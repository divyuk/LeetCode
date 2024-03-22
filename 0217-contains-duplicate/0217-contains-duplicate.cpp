class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> container;
        for(int i : nums){
            if(container.find(i) != container.end()) return 1;
            container.insert(i);
        }
        return 0;
    }
};