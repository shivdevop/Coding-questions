class Solution {
public:
    int findWays(vector<int>& arr, int k)
{
    // Write your code here.
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    //declare base cases 
    
    // for(int i=0;i<n;i++)
    // dp[i][0]=1;
    if(arr[0]==0)
    dp[0][0]=2;
    else 
    dp[0][0]=1;

    if(arr[0]!=0 && arr[0]<=k )
     dp[0][arr[0]]=1;   


      //jab bhi index 0 pe target value ke barabar ka call hoga toh true tabhi hoga jab wo arr[0] ke barabar hoga toh agar kabhi bhi 0th index ke corresponding arr[0]
    //target ka call ho toh wo true return kare..isliye we are doing this..and agar nhi call hota hai toh zabardasti 1 nhi return hoga
    //in this code return 0 ya 1 denote a way was found or not to achieve subset sum of k
    //how many parameters changing-->utne for loops 
    for(int index=1;index<n;index++)
    {
        for(int target=0;target<=k;target++)
        {
             int nottake=dp[index-1][target];
              int take=0;
             if(arr[index]<=target)
             take=dp[index-1][target-arr[index]];
          dp[index][target]=take + nottake;
        }
    }
    return dp[n-1][k];
}

    
    int findTargetSumWays(vector<int>& nums, int target) 
    
    {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        sum+=nums[i];

        //s1+s2=sum
        //s1-s2=target =>s2=(sum-target)/2;

        if(sum-target<0 || ((sum-target)%2)!=0)
        return 0;

      return findWays(nums,(sum-target)/2);        
    }
};