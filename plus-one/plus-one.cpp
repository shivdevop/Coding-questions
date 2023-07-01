class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int carry=1;
        int i=digits.size()-1;

        while(i>=0)
        {
            if(digits[i]<=8)
            {digits[i]+=1;
            break;}

            else
           {
             digits[i]=0;
             i--;
           }
        

        }
        if(digits[0]==0)
        digits.insert(digits.begin(),1);


        return digits;

    }
};