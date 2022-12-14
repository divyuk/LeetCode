class OrderedStream {
public:
    vector<string> stream ; //to get input
    int i=0;
    OrderedStream(int n) {
        stream.resize(n);
    }
    
    vector<string> insert(int id, string value) {
        vector<string> result;
        stream[id-1] = value; 
        while(i<stream.size() && stream[i]!="") 
        {
            result.push_back(stream[i]);
            i++;
        }
        return result;
    }
};