class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
      int max=*max_element(nums.begin(),nums.end());
      int sum=0;
      while(k>0)
      {
          sum+=max;
          max=max+1;
          k--;

      }
   return sum;

    }
};