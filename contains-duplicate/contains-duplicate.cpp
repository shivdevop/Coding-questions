class Solution {
public:
    // bool containsDuplicate(vector<int>& nums) 
    // {
    //    unordered_map<int,int> mpp;

    //     for(int i=0;i<nums.size();i++)
    //     mpp[nums[i]]++;

    //     for(int i=0;i<nums.size();i++)
    //     {
    //         if(mpp[nums[i]]>=2)
    //         return true;
    //     }
        
    //     return false;
    // }
      bool containsDuplicate(vector<int>& A)
    {
        sort(A.begin(),A.end());

        for(int i=1; i<A.size(); i++)
        {
            if(A[i]==A[i-1])
                return true;
        }
        return false;
    }
};