class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
     //three cases we will deal with 
        int s=0;
        int e=nums.size()-1;
        int mid;
        while(s<=e)
        {
            //three case we will deal with
            //if the middle element is same as the target element.
            
            mid=(s+e)/2;
            if(nums[mid]==target)
                return mid;
            //checking if the left part is sorted
            else if(nums[s]<=nums[mid])
            {
                if(target>=nums[s] && target<nums[mid])
                    e=mid-1;
                else
                    s=mid+1;
            }
            else
            {   //the else part means that the right part is sorted and when we are doing that targer is greater than than nums[mid], we also have to check whether it is smaller than the ending element bcoz it may happen that the target element is not even present in the right part and putting just one condition will cause a major error.
                
                if(target>=nums[mid] && target<=nums[e])
                    s=mid+1;
                else
                    e=mid-1;
            }
            
            
            
            
        }//end of while loop
        return -1;
    }
};