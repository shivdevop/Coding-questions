class Solution {
public:
    bool f(int index,vector<int>& nums,vector<int> &dp)
    {
        if(index>=nums.size()-1)
        return true;

        if(nums[index]==0)
        return false;

        if(dp[index]!=-1)
        return dp[index];
    
        dp[index]=false;

        // for(int i=1;i<=nums[index];i++)
        // dp[index]=dp[index] || f(index+i,nums,dp); -->this is unnecessary because if one function call can give us true why to unnecessary traverse further !!!!!

           for(int i=1;i<=nums[index];i++)
           { if(f(index+i,nums,dp))
                return dp[index]=true;
           }

        return dp[index];
    }
    bool canJump(vector<int>& nums) {

       int n=nums.size();
       vector<int> dp(n,-1);

        bool ans=f(0,nums,dp);//note we cannot do it from the back; the order matters  a lot and can give a completely different answer !!!!!
        return ans;
        
    }
};