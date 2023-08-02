class Solution {
public:

//    static int comp(pair<int,int> a,pair<int,int> b)
//     {
//         return a.second>b.second;
//     }
//     int majorityElement(vector<int>& nums) {
//      map<int,int> mpp;
//      for(int i=0;i<nums.size();i++)
//      mpp[nums[i]]++;
    
//       vector<pair<int,int>> v(mpp.begin(),mpp.end());
        
//         sort(v.begin(),v.end(),comp);
//     if(v[0].second>(nums.size()/2))
//     return v[0].first;  
//     return -1;
//     }

     int majorityElement(vector<int>& nums) {
         int candidate=nums[0],life=1;
         for(int i=1;i<nums.size();i++)
         {
             if(nums[i]==candidate)
             life++;
             else if(life==0)
             {
                 candidate=nums[i];
                 life++;
             }
             else
             life--;


         }
     return candidate;
     }
};