class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {   
        map<int,int> mp;
        stack<int> st;
        int n1=nums1.size();
        int n2=nums2.size();
        mp[nums2[n2-1]]=-1;//the next greater element for n-1th element of nums2 
        st.push(nums2[n2-1]);
        for(int i=n2-2;i>=0;i--)
        {
          while(!st.empty() && st.top()<=nums2[i])
          st.pop();
          if(!st.empty())
          mp[nums2[i]]=st.top();
          else
          mp[nums2[i]]=-1;
          st.push(nums2[i]);       
        }

        for(int i=0;i<n1;i++)
        {
          nums1[i]=mp[nums1[i]];
        }
        

        return nums1;
    }
};