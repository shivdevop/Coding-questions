class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0)
        return false;         
        if(n==1)
        return true;
        // if(n%3==0)
        // isPowerOfThree(n/3);//note this way we will never get the answer because we need to return our ans from the initial call as a result of which the last return false statement will be encountered in any case!!!
          if(n%3==0)
        return  isPowerOfThree(n/3);
 
        return false;
    }
};