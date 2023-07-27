class Solution {
public:

void merge(int low,int mid,int high,vector<int> &nums,int &count)
{
vector<int> temp;
int i=low,j=mid+1,r=mid+1;
 while(i<=mid)
 {
     while(r<=high && nums[i]>(long long)2*nums[r])
     {
         r++;
     }
     count+=r-mid-1;
    
         while(j<=high && nums[j]<=nums[i])
         temp.push_back(nums[j++]);
         
          temp.push_back(nums[i++]);
 }
    while(j<=high )
    temp.push_back(nums[j++]);

    for(int i=low;i<=high;i++)
    nums[i]=temp[i-low];


} 

void mergesort(int low,int high,vector<int> &nums,int &count)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(low,mid,nums,count);
        mergesort(mid+1,high,nums,count);
        merge(low,mid,high,nums,count);
    }

}

    int reversePairs(vector<int>& nums) {
      int count=0;
     int n=nums.size();
     mergesort(0,n-1,nums,count);

     return count;

    }
};