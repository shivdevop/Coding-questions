class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i=0,j=0,k=0;
        if(n==0){
            return;
        }
        else
        {
        while(i<m && j<n)
        {
            if(nums1[i]<nums2[j])
                ans.push_back(nums1[i++]);
            else if(nums1[i]>nums2[j])
                ans.push_back(nums2[j++]);
             else{
                 ans.push_back(nums1[i++]);
                 ans.push_back(nums2[j++]);
             }
        }
        while(i<m)
        {
            ans.push_back(nums1[i++]);
        }
         while(j<n)
        {
            ans.push_back(nums2[j++]);
        }
        int z=0;
        while(k<(m+n))
            
        {
            nums1[k++]=ans[z++];
        }
        }
    }
};