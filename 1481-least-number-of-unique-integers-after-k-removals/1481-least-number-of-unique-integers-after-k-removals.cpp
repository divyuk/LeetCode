class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int , int >umap;
        for(int i : arr)
            umap[i]++;
        vector<int>heap;
        for(auto i : umap)
            heap.push_back(i.second);
        make_heap(heap.begin() , heap.end() , greater<int>() );
        while(k>0){
            k-=heap.front();
            pop_heap(heap.begin() , heap.end() , greater<int>());
            if(k>=0)
                heap.pop_back();
        }
        return heap.size();
    }
};