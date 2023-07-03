class Solution {
public:
    bool isHappy(int n) 
    {   
        if(n==1)
        return true;
        unordered_map<int,int> mpp;
        mpp[n]++;
        while(n>1)
        {
            int newval=0;
            while(n>0)
            {
              int digit=n%10;
              n=n/10;
              newval+=(digit*digit);
            }
            n=newval;
            if(newval==1)
            return true;
            else if(mpp.find(newval)!=mpp.end())
            return false;
            mpp[newval]++;
        }
      return true;
    }
};