class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        typedef pair<int,int>P;
        priority_queue<P,vector<P>,greater<P>>topK; // min-heap
        unordered_map<int,int>freq;
        for(int num : nums) freq[num]++;
        
        for(auto ele : freq){
            int value = ele.first;
            int count = ele.second;
            topK.push({count,value});
            while(topK.size() > k){
                topK.pop();
            }
        }
        
        vector<int>top;
        while(!topK.empty()){
            top.push_back(topK.top().second);
            topK.pop();
        }
        return top;
    }
};