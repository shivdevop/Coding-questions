class Solution {
public:
    //  int f(int index,int target,vector<int> coins,vector<vector<int>>& dp)
    //  {

    //    if(index==0)
    //    {
    //       //  if(coins[index]>target)
    //       //  return 0;

    //        if((target%coins[index])==0) 
    //      return target/coins[index];
    //     //  else 
    //     //  return 0;
    //     return 1e9;
    //    }
       
    //    if(dp[index][target]!=-1)
    //    return dp[index][target];
    
    //    int nottake=0+f(index-1,target,coins,dp);
    //    int take=INT_MAX;
    //    if(coins[index]<=target)
    //    take=1+ f(index,target-coins[index],coins,dp);//ek baar koi particular coin lene ke baad bhi ye ho sakta hai ki usi ki hi aur coins leni pad jaye

    //    return dp[index][target]=min(nottake,take); 

    //  } 

    int coinChange(vector<int>& coins, int amount)
    {
     int n=coins.size();
     vector<vector<int>> dp(n,vector<int>(amount+1,0));
     
     //BASE CASES 
     for(int t=0;t<=amount;t++)
     {
       if(t%coins[0] ==0)
       dp[0][t]=t/coins[0];

       else 
       dp[0][t]=1e9;
     }
     

    for(int index=1;index<n;index++)
    {
      for(int target=0;target<=amount;target++)
      {
         int nottake=0+dp[index-1][target];
       int take=INT_MAX;
       if(coins[index]<=target)
       take=1+ dp[index][target-coins[index]];
       //ek baar koi particular coin lene ke baad bhi ye ho sakta hai ki usi ki hi aur coins leni pad jaye

       dp[index][target]=min(nottake,take); 
      }
    }
    //end of for
    
  if (dp[n-1][amount] >=1e9)
  return -1;
  return dp[n-1][amount];
    }
};