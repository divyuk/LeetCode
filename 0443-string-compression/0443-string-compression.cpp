class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(),count=1;
        int index = 0;
        int i =0;
        while (i<n)
        {
            int j =i;
            while (j<n and chars[i] == chars[j])
                j++;
            chars[index++] = chars[i];
            if(j-i>1)
               for(char d: to_string(j-i))
                    chars[index++] = d;
            i=j;
        }
        return index;
    }
};