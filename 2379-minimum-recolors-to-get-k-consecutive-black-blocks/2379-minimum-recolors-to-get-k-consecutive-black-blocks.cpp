class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int w =0;
        int back=0,front=0,ans=INT_MAX;
        while(front<n){
            if(blocks[front] == 'W') w++;
            if(front-back+1 == k){
                ans = min(ans,w);
                if(blocks[back] == 'W') w--; // Since window is moving now
                back++;
            }
            front++;
        }
        return ans;
    }
};