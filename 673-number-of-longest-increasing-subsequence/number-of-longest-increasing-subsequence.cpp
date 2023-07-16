class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {


     int n=arr.size();
      vector<int> dp(n,1);   
      vector<int> count(n,1);   
      
      int maxi=1;

       
    for(int i=0;i<n;i++)
    {    
      
        for(int prev=0;prev<i;prev++)
        {
            if(arr[prev]<arr[i] && dp[prev]+1>dp[i])
            {
                dp[i]=dp[prev]+1;
                count[i]=count[prev];//shouldnt be initialized to 1
            
            }
            else if(arr[prev]<arr[i] && dp[prev]+1==dp[i])
            count[i]=count[i]+count[prev];
        }
		
		if(dp[i]>maxi)
		{
			maxi=dp[i];
	
		}
    
    }///end of for-->dp has been calculated
    int ans=0;
   for(int i=0;i<n;i++)
   {
       if(dp[i]==maxi)
       ans+=count[i];
   }

   return ans;
    }
};