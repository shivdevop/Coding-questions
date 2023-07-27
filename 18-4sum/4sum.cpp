class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    { 
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n<4)
        return {};
        set<vector<int>> s;
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int k=j+1;
                int l=n-1;
                while(k<l)
                {   
                     long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[k] + nums[l];
                    if(sum==target)
                    {
                         s.insert({nums[i],nums[j],nums[k],nums[l]});
                         k++;
                         l--;
                          while(k<l && nums[k]==nums[k-1])
                          k++;
                         while(k<l && nums[l]==nums[l+1])
                          l--;

                    }
                    else if (sum<target)
                    {
                        k++;
                        while(k<l && nums[k]==nums[k-1])
                          k++;

                    }
                    else
                    {
                        l--;
                        while(k<l && nums[l]==nums[l+1])
                          l--;
                    }
                }
            }
        }
      vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};