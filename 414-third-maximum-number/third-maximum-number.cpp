class Solution {
public:
    int thirdMax(vector<int>& nums) {
       set<int> s(nums.begin(),nums.end());
       priority_queue<int> q(s.begin(),s.end());
      if(q.size()>2)
      {
          q.pop();
          q.pop();
      }
      return q.top();

    }
};