class Solution {
public:
    
    bool isValid(vector<vector<int>>& image, int i,int j , int r,int c,int old ){
        if(i>=0 and i<r and j>=0 and j<=c and image[i][j]==old)
            return 1;
        return 0;
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size();
        int c = image[0].size();
        
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int old = image[sr][sc];
        if(old == color) return image;
        image[sr][sc] = color;
        
        while(!q.empty()){
            
            int size = q.size();
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                int ax[4] = {1,-1,0,0};
                int ay[4] = {0,0,1,-1};
                
                for(int i =0;i<4;i++){  
                    int dx = ax[i] + x;
                    int dy = ay[i] + y;
                    
                    if(isValid(image, dx,dy ,r,c,old )){
                        q.push({dx,dy});
                        image[dx][dy] = color;
                    }
                }
            }
        
        }
        return image;
        
    }
};