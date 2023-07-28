class Solution {
public:
   bool f(int mid,vector<int> piles,int hours)
   {     int n = piles.size();
    int totalHours = 0;
    for (int i = 0; i < n; i++) {
        totalHours += (piles[i] + mid - 1) / mid;
        if (totalHours > hours) {
            return false;
        }
    }
    return true;
   }


    int minEatingSpeed(vector<int>& piles, int h) {
     int n=piles.size();
     sort(piles.begin(),piles.end());
     int low=1;
     int high=piles[n-1];
     int ans;
     while(low<=high)
     {
         int mid=(low+high)/2;
         if(f(mid,piles,h))
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