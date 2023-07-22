class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int prev=0;
        int ans=0;
        for(int current=1;current<n;current++)
        {
            if(intervals[current][0]<intervals[prev][1])
            {   ans++;
                if(intervals[current][1]<=intervals[prev][1])
                prev=current;
            }
            else
            prev=current;
        }
        return ans;
    }
};