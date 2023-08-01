class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int x=*max_element(nums1.begin(),nums1.end());
        vector<int> hash(x+1,0);
        for(int i=0;i<nums1.size();i++)
        hash[nums1[i]]++;

        vector<int> ans;
        for(int i=0;i<nums2.size();i++)
        {
            if(nums2[i]<=x && hash[nums2[i]]>0)//we also need to ensure whether nums2[i] is a valid index for hash array or not otherwise directly accessing it would result in runtime error 
            {
                ans.push_back(nums2[i]);
                hash[nums2[i]]--;
            }
        }
        return ans;
    }
};