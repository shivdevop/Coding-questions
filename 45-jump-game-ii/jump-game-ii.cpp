class Solution {
public:
     int f(int index,vector<int>& nums,vector<int> &dp)
    {
        if(index>=nums.size()-1)
        return 0;

        if(nums[index]==0)
        return 1e9;

        if(dp[index]!=-1)
        return dp[index];
    
       int mini=1e9;

        // for(int i=1;i<=nums[index];i++)
        // dp[index]=dp[index] || f(index+i,nums,dp); -->this is unnecessary because if one function call can give us true why to unnecessary traverse further !!!!!

           for(int i=1;i<=nums[index];i++)
           {   int steps=1+f(index+i,nums,dp);
               mini=min(mini,steps);
           }

        return dp[index]=mini;
    }
    int jump(vector<int>& nums) {
         int n=nums.size();
       vector<int> dp(n,-1);

        int ans=f(0,nums,dp);
        return ans;
    }
};