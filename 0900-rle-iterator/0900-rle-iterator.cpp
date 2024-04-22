class RLEIterator {
private:
    int currFreq;
    int currEle;
    queue<int> que;
public:
    RLEIterator(vector<int>& encoding) {
        currFreq = 0;
        currEle = -1;
        for (int ele : encoding) que.push(ele);
    }
    
    int next(int n) {
        while (n > 0) {
            if (currFreq == 0) {
                if (que.empty()) return -1;
                else {
                    currFreq = que.front();
                    que.pop();
                    currEle = que.front();
                    que.pop();
                }
            }
            int use = min(n, currFreq);
            currFreq -= use;
            n -= use;
        }
        return currEle;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */