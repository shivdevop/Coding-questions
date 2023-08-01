class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1)
        return true;
       int low=1,high=num/2;
       while(low<=high)
       {
           int mid=(low+high)/2;
          long long result=(long long) mid*mid;
           if(result==num)
           return true;
           else if(result>num)
           high=mid-1;
           else
           low=mid+1;
       }
       return false;
    }
};