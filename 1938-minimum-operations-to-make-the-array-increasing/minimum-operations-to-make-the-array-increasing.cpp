class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int minop=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<=nums[i-1])
            {minop+=nums[i-1]-nums[i]+1;
            nums[i]=nums[i-1]+1;}
        }
        return minop;
    }
};