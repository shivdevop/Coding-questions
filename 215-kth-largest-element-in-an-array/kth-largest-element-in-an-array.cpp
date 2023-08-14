class Solution {
public:
   
    int findKthLargest(vector<int>& nums, int k)
    {
       priority_queue<int,vector<int>,greater<int>> min_h(nums.begin(),nums.end());
        for(int i=1;i<=nums.size()-k;i++)
            min_h.pop();
        return min_h.top(); 
    }
};