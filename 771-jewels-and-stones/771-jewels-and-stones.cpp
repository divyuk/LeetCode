class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int c =0;
        for(char j : jewels){
            for(char s : stones){
                if(j==s)
                    c++;
            }
        }
        return c;
    }
};