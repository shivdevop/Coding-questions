class Solution {
public:
   //everytime we will be making a new number by adding all digits
    int addDigits(int num) 
    {  
        int temp=num,digits=0;
        while(temp>0)
        {
            temp/=10;
            digits++;
        }
        if(digits==1)
        return num;
        int sum=0;
        temp=num;

        while(digits>1)
        {
            digits=0;
            sum=0;
         while(temp>0)
        {   int digit=temp%10;
            temp/=10;
            digits++;
            
            sum=sum+digit;
        }
        temp=sum;
            
        }
        return sum;
    }
};