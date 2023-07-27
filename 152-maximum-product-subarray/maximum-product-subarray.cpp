class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n=nums.size();
        int maxi=INT_MIN;
        int prefix_prod=1,suffix_prod=1;
     
        for(int i=0;i<n;i++)
        {
            if(prefix_prod==0)prefix_prod=1;
            if(suffix_prod==0)suffix_prod=1;      
           
           
            prefix_prod=prefix_prod*nums[i];
            suffix_prod=suffix_prod*nums[n-i-1]; 
            maxi=max(maxi,max(prefix_prod,suffix_prod));
        }
    
        return maxi;
    }
};