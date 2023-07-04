class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
       vector<string> ans;
        if(nums.size()==0)
        return {};
        if(nums.size()==1)
        {ans.push_back(to_string(nums[0]));
        return ans;}
        string s="";
        s=s+to_string(nums[0]);
     
         int i;
        for( i=1;i<nums.size();i++)
        { 
            while(i<nums.size() && nums[i]==(nums[i-1]+1))
            i++;
            
            if(to_string(nums[i-1])!=s)
            s+="->"+to_string(nums[i-1]);

            ans.push_back(s);

            if(i<nums.size())
            s=to_string(nums[i]);

        }
        cout<<s;
        if(s!=ans[ans.size()-1])
        ans.push_back(s);
                
        // if(to_string(nums[i-1])==s)
        // ans.push_back(s);
        return ans;
    }
};