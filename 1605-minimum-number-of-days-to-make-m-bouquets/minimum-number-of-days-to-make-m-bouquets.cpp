class Solution {
public:
   bool f(int mid,vector<int> bloomDay,int m,int k)
   {  //mid refers to a certain blooming day 
      int consecutive=0;
      int bouquets=0;
      for(int i=0;i<bloomDay.size();i++)
      {
          if(bloomDay[i]<=mid)
          {
              consecutive++;//consecutive bloomed flowers count 
          }
          else
          {
              bouquets+=consecutive/k;
              consecutive=0;
          }
      
      }
     bouquets+=consecutive/k;
     return bouquets>=m;    
  
   }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
     int n=bloomDay.size();
        long long x=(long long)m*k; //we cannot store integer into a long variable so we have to make the right side  as LL as well otherwise we will encounter runtime error !!!!
        if(x>n)
        return -1;
        int low=INT_MAX;
        int high=INT_MIN;
        for(int i=0;i<n;i++)
        {
            low=min(low,bloomDay[i]);
            high=max(high,bloomDay[i]);
        }
         int ans=-1;
        while(low<=high)
        { 
            int mid=(low+high)/2;
            if(f(mid,bloomDay,m,k))
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
          
        }
        return ans;
    }
};