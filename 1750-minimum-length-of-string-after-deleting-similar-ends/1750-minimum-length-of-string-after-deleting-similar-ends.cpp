class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int front = 0, rear = n-1,len=0;
        vector<int>store(3,0); int f = 0;
      
            while(front<rear and s[front]== s[rear]){
               char ch = s[front];
                while(front<rear and s[front] == ch) front++;
                while(rear>=front and s[rear] ==ch) rear--;
            }
   
        return rear-front+1;
    }
};