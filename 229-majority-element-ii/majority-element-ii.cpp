  class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
       vector<int> ans;
       int candidate1=0,candidate2=0,life1=0,life2=0;

       for(int i=0;i<nums.size();i++)
       {
         if(nums[i]==candidate1)
         life1++;
         else if(nums[i]==candidate2)
          life2++;
         else if(life1==0)
         {
             candidate1=nums[i];
             life1=1;
         }
         else if(life2==0)
         {
             candidate2=nums[i];
             life2=1;
         }
         else
         {
             life1--;
             life2--;
         }
       }//end of for
    
       //the candidates we get we need to be sure that their count satisfies the given condition !!!!
       int target=floor(nums.size()/3);
       int count1=0,count2=0;
       for(int i=0;i<nums.size();i++){
         if(nums[i]==candidate1)
         count1++;
         else if(nums[i]==candidate2)
         count2++;
       }
       if(count1>target)
       ans.push_back(candidate1);
       if(count2>target)
       ans.push_back(candidate2);
         return ans;
    }
}; 