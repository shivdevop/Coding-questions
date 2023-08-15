class Solution {
public:
    bool checkRecord(string s) {
        
        int consecutivedays=0,absent=0;
        for(int i=0;i<s.length();i++)
        {   char ch=s[i];
            if(ch=='A')
            {  consecutivedays=0;
                absent++;
                if(absent>=2)
                return false;
            }
            else if(ch=='L')
            {
                consecutivedays++;
                if(consecutivedays>=3)
                return false;
            }
            else
            consecutivedays=0;
        }

        return true;
    }
};