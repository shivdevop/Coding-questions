class Solution {
public:
    static bool comp(pair<int,int> a,pair<int,int> b)
    {
       return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {  
        vector<int> ans;
        map<int,int> mpp;//element and count
        for(int i=0;i<nums.size();i++)
        mpp[nums[i]]++;

        vector<pair<int,int>> v(mpp.begin(),mpp.end());//converting map to a vector of pairs

        sort(v.begin(),v.end(),comp);

        for(int i=0;i<k;i++)
        ans.push_back(v[i].first);

        return ans;

    
        
    }
};