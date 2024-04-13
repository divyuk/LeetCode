class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea =0;
        int n = heights.size();
        stack<pair<int,int>>stk; // index , height
        for(int i = 0; i<n; i++ ){
            int start = i;
            while(!stk.empty() and stk.top().second > heights[i] ) {
                int index= stk.top().first;
                int bigHeight = stk.top().second;
                stk.pop();
                maxArea = max(maxArea,bigHeight*(i-index) );
                start = index;
            }
            stk.push({start, heights[i]  });
        }
        while(!stk.empty() ){
            maxArea = max(maxArea , (n- stk.top().first)*stk.top().second);
            stk.pop();
        }
        return maxArea;
    }
};