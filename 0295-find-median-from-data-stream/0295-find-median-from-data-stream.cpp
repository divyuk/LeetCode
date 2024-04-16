class MedianFinder {    

/* The idea of dividing existing numbers into several ranges:

   Say we already have 10k numbers in vector, 
   each time adding a number requires sorting all 10k numbers, which is slow.

   To optimize, we can store 10k numbers in several (say 10) vectors, 
   and nums in each vector are sorted.
   
   Then each time we add a number, just need to find one vector with correct range,
   insert the number and sort this vector only. Since its size is relatively small, it's fast.
   
   When we have a vector's size greater than a threshold, just split it into two halfs.
   
*/

public:
    vector<vector<int>*> raid; // store all ranges
    int total_size;

    MedianFinder() {
        total_size=0;
        raid.push_back(new vector<int> ());
    }
    
    void addNum(int num) {
        vector<int>* correctRange=NULL;
        int targetIndex;
        
        // find the correct range to insert given num
        for (int i=0; i<raid.size(); i++)
            if ( raid.size()==1 ||
                 (i==0 && num<=raid[i]->back()) || 
                 (i==raid.size()-1 && num>=raid[i]->at(0)) ||
                 (raid[i]->at(0)<=num && num<=raid[i]->back()) ||
                 (num > raid[i]->back() && num < raid[i+1]->front()) )
            {
                correctRange = raid[i];
                targetIndex = i;
                break;
            }
        
        // put num at back of correct range, and sort it to keep increasing sequence
        total_size++;
        correctRange->push_back(num);
        sort(correctRange->begin(), correctRange->end());
                
        // if current range's size > threshold, split it into two halfs and add them back to this.raid
        const int max_size = 30;
        int len = correctRange->size();
        if (len > max_size) {
            vector<int> *half1 = new vector<int>(correctRange->begin(), correctRange->begin()+len/2);
            vector<int> *half2 = new vector<int>(correctRange->begin()+len/2, correctRange->end());
            
            delete correctRange;
            raid[targetIndex]=half2;
            raid.insert(raid.begin() + targetIndex, half1);
        }
        
    }

    // iterate thru all ranges in this.raid to find median value
    double findMedian() {
        if (total_size==0)
            return 0;
        
        int mid1 = total_size/2;
        int mid2 = mid1 + 1;
        
        int leftCount=0;
        double first, second;
        for (auto r : raid) {
            if (leftCount<mid1 && mid1<=leftCount+r->size())
                first = r->at(mid1 - leftCount - 1);
                
            if (leftCount<mid2 && mid2<=leftCount+r->size()) {
                second = r->at(mid2 - leftCount - 1);
                break;
            }
            leftCount += r->size();
        }
        
        if (total_size % 2)
            return second;
        else
            return (first + second)/2;
    }
};