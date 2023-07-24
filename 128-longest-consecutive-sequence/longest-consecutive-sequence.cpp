class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {  
     if(nums.size()==0 || nums.size()==0)
     return 0;   
     unordered_set<int> s(nums.begin(),nums.end());
     int ans=INT_MIN;
     int n=nums.size();

     
     for(auto it:s)
     {

         if(s.find(it-1)==s.end())
         {
             int count=1;
             int num=it+1;
             while(s.find(num)!=s.end())
             {count++;
             num++;}
              ans=max(ans,count);
         }
        
     }

     return ans;
        
    }
};