class DetectSquares {
   
public:
    map<pair<int,int> , int> points;
    DetectSquares() : points() {}

    
    void add(vector<int> point) {
        points[ {point[0] , point[1]} ]++;
    }
    
    int count(vector<int> point) {
        int qx  = point[0];
        int qy  = point[1];
        int cnt = 0;
        for( auto p : points ){
            int x = p.first.first;
            int y = p.first.second;
            if( x!=qx and y!= qy and  abs(qx-x) == abs(qy - y) ) {
                int a = points[{x,y}];
                int b = points[{x,qy}];
                int c = points[{qx,y}];
                cnt+=a*b*c;
            }
        }
        return cnt;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */