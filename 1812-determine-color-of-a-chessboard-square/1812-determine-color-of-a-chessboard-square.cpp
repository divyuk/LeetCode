class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int col = coordinates[0];
        int row = coordinates[1];
        cout<<col<<" "<<row; 
        if((col-97) %2 ==0 and (row-49) %2 == 0 )
            return false;
        if((col-97) %2 !=0 and (row-49) %2 != 0 )
            return false;     
        
        
        
        
 
        return true;
    }
};