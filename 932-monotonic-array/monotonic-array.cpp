class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return true;
        int flag;
        if(nums[0]<=nums[n-1])
        flag=0;
        else 
        flag=1;

        for(int i=0;i<nums.size()-1;i++)
        {
            if(flag==0 && nums[i]>nums[i+1])
            return false;
            else if(flag==1 && nums[i]<nums[i+1])
            return false;
        }
        return true;
    }
};