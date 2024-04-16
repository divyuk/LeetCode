class MedianFinder {
public:
    priority_queue<int> left_max_heap; //max heap
    priority_queue<int, vector<int>, greater<int>> right_min_heap; //min heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_max_heap.empty() || num < left_max_heap.top()) left_max_heap.push(num);
         else  right_min_heap.push(num);
        
        //always maintain left_max_heap size one greater than rigfht_min_heap size
        //else both should be equal
        if(abs((int)left_max_heap.size() - (int)right_min_heap.size()) > 1) {
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        } else if(left_max_heap.size() < right_min_heap.size()) {
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
        
    }
    
    double findMedian() {
        if(left_max_heap.size() == right_min_heap.size()) //even case
            return (double)(left_max_heap.top()+right_min_heap.top())/2;
        //odd case
        return left_max_heap.top();
    }
};

/** run on 1 3 4 5 7 9
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */