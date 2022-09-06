class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int>ans;
        int n = encoded.size();
        ans.push_back(first);
        int value =0;
        for(int i =0;i<n;i++){
            value = encoded[i] ^ first;
            ans.push_back(value);
            first = value;
        }
        return ans;
    }

};