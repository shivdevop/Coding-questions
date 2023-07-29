class Solution {
public:
    int findShortestSubArray(vector<int>& nums) 
    {
        map<int,int> freq;
        int degree=INT_MIN;
        map<int,pair<int,int>> mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
            degree=max(degree,freq[nums[i]]);
        }

        for(int i=0;i<n;i++)
        {
            if(freq[nums[i]]==degree && mp.find(nums[i])==mp.end())
            {
                
                for(int j=n-1;j>=0;j--)
                {
                    if(nums[j]==nums[i])
                    {mp[nums[i]]={i,j};
                    break;}    
                }
            }
        }
        
        int ans=INT_MAX;
        for(auto it:mp)
        { 
            int diff=it.second.second - it.second.first + 1;
            ans=min(ans,diff);

        }
        return ans;
    }
};