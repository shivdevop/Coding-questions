class Solution {
public:
    void f(int index,vector<int> nums,vector<int>& ls,vector<vector<int>> &ans)
    {
         if(index==nums.size())
        { ans.push_back(ls);
           return;}

           
      ls.push_back(nums[index]);
     f(index+1,nums,ls,ans);

     //not_take
     ls.pop_back();
     while(index+1<nums.size() && nums[index+1]==nums[index])
     index++;
     f(index+1,nums,ls,ans);


    }

   

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       sort(nums.begin(),nums.end());
         vector<vector<int>> ans;
        vector<int> ls;
        f(0,nums,ls,ans);
        return ans;  
    }
};