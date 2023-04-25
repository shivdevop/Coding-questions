class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int start=0,end=0,zeros=0,maxi=INT_MIN;

        for(end=0;end<nums.size();end++)
        {
            if(nums[end]==0)
            zeros++;
            while(zeros>k)
            {
                if(nums[start]==0)
                zeros--;

                start++;
            }
            maxi=max(maxi,end-start+1);
        }
        return maxi;
    }
};