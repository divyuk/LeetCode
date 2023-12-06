class Solution {
public:
    int totalMoney(int n) {
          //completeWeek indicates how many complete week Hercy added money
        //to the bank.
        int completeWeek = n / 7;
        
        //leftDays indicates number of left days after completeWeek turn.
        int leftDays = n % 7;
        
        //starting money in the last week
        int startMoney = completeWeek + 1;
        
        //sum of AP series : Sn = (n * [2 * a + (n - 1) * d]) / 2
        int completeWeekMoneysum = (completeWeek * (2 * 28 + (completeWeek - 1) * 7)) / 2;
        
        int leftDaysMoneySum = (leftDays * (2 * startMoney + (leftDays - 1) * 1)) / 2;
        
        return (completeWeekMoneysum + leftDaysMoneySum);
    }
};