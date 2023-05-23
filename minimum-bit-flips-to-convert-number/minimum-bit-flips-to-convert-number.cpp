class Solution {
public:
    int minBitFlips(int start, int goal) 
    {
        int count=0;
        int bit1,bit2;

        while(start>0 && goal>0)
        {
            bit1=start&1;
            bit2=goal&1;
            if(bit1!=bit2)
            count++;
            start=start>>1;
            goal=goal>>1;
        }
        while(start>0)
        {   int bit=start&1;
            if(bit==1)
            count++;
            start=start>>1;
            
        }
        while(goal>0)
        {  int bit=goal&1;
            if(bit==1)
            count++;

            goal=goal>>1;
     
        }

        
        return count;
    }
};