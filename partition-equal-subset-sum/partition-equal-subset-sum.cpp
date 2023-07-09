class Solution {
public:
bool subsetSumToK(int n, int k, vector<int> &arr)
 {
    // Write your code here.
    vector<vector<bool>> dp(n,vector<bool>(k+1,0)); //initially all set to false 

    //define base cases 
    //koi bhi valid index ke corresponding agar target=0 call ho iska matlab subsequence mil chuka hai !!!
    
    for(int i=0;i<n;i++)
    dp[i][0]=1;
    
    if(arr[0]<=k)
    dp[0][arr[0]]=1;
    //agar kabhi upar line ka zarurat pad rha iska matlab target ka place mei arr[0] raha hoga.
  

    //jitne changing parameters utne loops  
    for(int index=1;index<n;index++)
    {
        for(int target=1;target<k+1;target++)
        {
                bool nottake=dp[index-1][target];

                  bool take = false;
                if(arr[index]<=target)
              take=dp[index-1][target-arr[index]];         

         dp[index][target]=take | nottake;
        }
    }
    return dp[n-1][k]; 

}
    bool canPartition(vector<int>& nums) {

        //if anyone subset has a value of sum/2 then other will automatically have

        int sum=0,n=nums.size();

        for(int i=0;i<n;i++)
        sum+=nums[i];

        if(sum%2!=0)
        return false;
        
        int target=sum/2;

        return subsetSumToK(n,target,nums);
        
    }
};