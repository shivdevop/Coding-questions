class Solution {
public:
    // int f(int index,int prev,vector<int>nums,vector<vector<int>> &dp)
    // {  

    //    //base cases
    //    if(index==nums.size())
    //    return 0; 

    //   if(dp[index][prev+1]!=-1)
    //   return dp[index][prev+1];

    //   int not_take=0+f(index+1,prev,nums,dp);
    //   int take=0;
    //   if(prev==-1 || nums[index]>nums[prev])
    //   take=1+f(index+1,index,nums,dp);

    //   return dp[index][prev+1]=max(not_take,take);
    
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        //two paramters-->curr_index and prev index
        //index=0-n-1 , prev= -1 to n-1
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        //base cases 
        // for(prev=-1;i<=n-1;i++)
       // dp[n][prev+1]=0; //not necessary -->already initializing to 0 while declaring !!!

        for(int index=n-1;index>=0;index--)
        {
            for(int prev=n-1;prev>=-1;prev--)
            {
                   int not_take=0+dp[index+1][prev+1];
                    int take=0;
                  if(prev==-1 || nums[index]>nums[prev])
                    take=1+dp[index+1][index+1]; //note that index is representing the actual index traversing over our array and if that index is becoming previous we know that in dp it will be stored as +1; so if we are making the current index as prev then we will store it as index+1.

                    dp[index][prev+1]=max(take,not_take);
            }
        }
        
        return dp[0][0];
    }
};