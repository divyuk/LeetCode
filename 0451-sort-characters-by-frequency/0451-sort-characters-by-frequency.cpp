class Solution {
public:
    string frequencySort(string s) {
        int count[128] = {};
        for (char c : s) count[c]++;
        sort(s.begin() , s.end() , [&](char a, char b){
            return (count[a]>count[b] || (count[a]==count[b] and a<b) );
        });
        return s;
    }
};