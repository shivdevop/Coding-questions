class Solution {
public:
bool f(int mid,vector<int> nums,int threshold)
{
    int sum=0;
    for(int i=0;i<nums.size();i++)
    {
        sum+= ceil(double(nums[i])/double(mid));
        cout<<sum;
        if(sum>threshold)
        return false;
    }
    return true;
}
   
    int smallestDivisor(vector<int>& nums, int threshold) {

       int low=1;
        int high=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            high=max(high,nums[i]);
        }
        int ans;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(f(mid,nums,threshold))
            {
                high=mid-1;
                ans=mid;
            }
            else
            low=mid+1;
        }

        return ans;


    }
};