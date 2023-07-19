class Solution {
public:
void f(int index,int k,vector<int> candidates,vector<int>& ls,vector<vector<int>> &ans)
   {
     //base cases
      if(k==0)
      {
          ans.push_back(ls);
          return;
      }
      if(index>=candidates.size())
      return;
      if(k<0)
      return;


     //take
     ls.push_back(candidates[index]);
     f(index,k-candidates[index],candidates,ls,ans);
     //not_take
     ls.pop_back();
     f(index+1,k,candidates,ls,ans);

   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> ls;
        f(0,target,candidates,ls,ans);
        return ans;

        
    }
};