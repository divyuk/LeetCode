class Solution {
public:
   int countTime(string time)
    {
        int count=0;
        
        for(int hour=0;hour<24;hour++)
        {
            for(int minute=0;minute<60;minute++)
            {
                string hour_string=to_string(hour);
                string minute_string=to_string(minute);
                if(hour_string.size()==1)
                    hour_string="0"+hour_string;
                if(minute_string.size()==1)
                    minute_string="0"+minute_string;
                string new_time=hour_string+":"+minute_string;
                for(int i=0;i<5;i++){
                    if(new_time[i]!=time[i]&&time[i]!='?')
                        break;
                    if(i==4)
                        count++;
                }
            }
        }
        return count;
    }
};