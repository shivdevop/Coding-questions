class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n=coins.size();
     vector<vector<int>> dp(n,vector<int>(amount+1,0));

     //define the base cases
       for(int t=0;t<=amount;t++)
     {
        if(t%coins[0]==0)
        dp[0][t]=1;
        else
        dp[0][t]=0;
     }

     //changing paramters for loop
      for(int index=1;index<n;index++)
    {
      for(int target=0;target<=amount;target++)
      {
         int nottake=dp[index-1][target];
       int take=0;
       if(coins[index]<=target)
       take=dp[index][target-coins[index]];
       //ek baar koi particular coin lene ke baad bhi ye ho sakta hai ki usi ki hi aur coins leni pad jaye

       dp[index][target]=nottake+take; 
      }
    }
    return dp[n-1][amount];
    }
};