class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
        int totaltime=0;
        int currEndTime=0;
        int flag=0;
        for(int i=0;i<timeSeries.size();i++)
        {
            if(timeSeries[i]<=currEndTime && flag==1)
            {
                totaltime=totaltime-(currEndTime-timeSeries[i]+1) + (duration);
            }
            else
            {  flag=1;
                totaltime+=duration;
            }
            currEndTime=timeSeries[i]+duration-1;
        }
        return totaltime;
    }
};