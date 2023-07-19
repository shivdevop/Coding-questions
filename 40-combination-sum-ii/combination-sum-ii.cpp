class Solution {
public:
 void f(int index,int k,vector<int> candidates,vector<int>& ls,vector<vector<int>> &ans)
   {
     //base cases
      if(k==0)
      { 
        //  if(find(ans.begin(),ans.end(),ls)==ans.end())
          ans.push_back(ls);
          return;
      }
      if(index>=candidates.size())
      return;
      if(k<0)
      return;


   
      ls.push_back(candidates[index]);
     f(index+1,k-candidates[index],candidates,ls,ans);

     //not_take
     ls.pop_back();
     while(index+1<candidates.size() && candidates[index+1]==candidates[index])
     index++;
     f(index+1,k,candidates,ls,ans);
   }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {   sort(candidates.begin(),candidates.end());
         vector<vector<int>> ans;
        vector<int> ls;
        f(0,target,candidates,ls,ans);
        return ans;

        
    }
};