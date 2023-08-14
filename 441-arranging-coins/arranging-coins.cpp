class Solution {
public:
    int arrangeCoins(int n) {
        int low=1;
        int high=n;
        int ans;
        while(low<=high)
        {
            long long mid=((long long)low+high)/2;
            long long coins=(long long) mid*(mid+1)/2;
            if(coins<=n)
            {
                ans=mid;
                low=mid+1;
            }
            else
            high=mid-1;

        }
        return ans;
    }
};