class Solution {
public:
   int f(int sumlimit,int n,vector<int> nums)
   {
       int currentsum=0;
       int subarrays=1;
       for(int i=0;i<n;i++)
       {
           if(currentsum+nums[i]<=sumlimit)
           currentsum+=nums[i];
           else
           {
               subarrays++;
               currentsum=nums[i];
           }
       }
       return subarrays;
   }

   
    int splitArray(vector<int>& nums, int k) {
    //it can be told that k should be equal to 1 --> so that the entire array should be taken as the subarray !!!
    int high=accumulate(nums.begin(),nums.end(),0);
    int low=*max_element(nums.begin(),nums.end());
    int n=nums.size();
    int ans;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(f(mid,n,nums)>k)
        low=mid+1;//the sum limit was small due to which the number of subarrays were increasing
        else
        {
            ans=mid;
            high=mid-1;

        }
    }     
    return ans;
    }
};