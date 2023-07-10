class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {  
       int n=nums.size();
       stack<int> st;
       vector<int> result(n,-1);
       
       for(int i=0;i<n*2;i++)
       {   
           int index=i%n;
           while(!st.empty() && nums[index]>nums[st.top()])
           {
           result[st.top()]=nums[index];
           st.pop();
           }
          //now either the stack is empty or the incoming element is smaller 
          st.push(index);
       }

       return result;
    }

};