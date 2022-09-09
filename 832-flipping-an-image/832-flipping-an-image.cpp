class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>>ans;
        int n = image.size();
        for(auto &it : image){
            int left =0,right = n-1;
            while (left<=right)
            {
                if(left==right)
                it[right]= it[right] == 0 ? 1:0 ;
                swap(it[left],it[right]);
                it[left]= it[left] == 0 ? 1:0 ;
                it[right]= it[right] == 0 ? 1:0 ;
                left++,right--;
            }
            
        }
        return image;
    }
};