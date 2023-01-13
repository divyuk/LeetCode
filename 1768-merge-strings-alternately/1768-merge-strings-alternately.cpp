class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        string merge = "";
        int i =0, j = 0;
        while(i<n and j<m){
            merge = merge + word1[i++] + word2[j++];
        }
        while(i!=n)
            merge = merge + word1[i++];
        while(j!=m)
            merge = merge + word2[j++];
        
        return merge;
    }
};