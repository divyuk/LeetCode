class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> result;
        vector<int>pos;
        int n = s.size();

        for(int j =0;j<n;j++)
            if(s[j] == c)
                pos.push_back(j);

        int left =0,right=0;
        int m = pos.size();
        for(int i =0;i<n;i++)
        {
            if(i>pos[right]){
               left  = right;
               if(right<m-1)
                    right++;
            }
            result.push_back(min( abs(pos[left]-i) ,
                                  abs(pos[right]-i)));
        }
        
        return result;
    }
};