class Solution {
public:
   void f(int index,int remaining,int target,vector<int> nums,vector<int>& ls,vector<vector<int>> &ans)
   {
     //base cases
      if(target==0 && remaining==0)
      {   ans.push_back(ls);
          return; }
      if(index>=nums.size() || remaining<=0)
      return;
      if(target<0)
      return;


   
      ls.push_back(nums[index]);
     f(index+1,remaining-1,target-nums[index],nums,ls,ans);

     //not_take
     ls.pop_back();
     f(index+1,remaining,target,nums,ls,ans);
   }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for(int i=1;i<=9;i++)
        nums.push_back(i);

        vector<vector<int>> ans;
        vector<int> ls;
        f(0,k,n,nums,ls,ans);
        return ans;
        
    }
};