class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        int j=n-1;
        while(i<=j)
        {
            while(i<n && nums[i]%2==0)
            i++;
            while(j>=0 && nums[j]%2)
            j--;
            if(i<=j)
            swap(nums[i++],nums[j--]);
        }
        return nums;
    }
};