class Solution {
public:
    int titleToNumber(string columnTitle) 
    {   int length=columnTitle.length();
        int ans=0;
        for(int i=0;i<length;i++)
        {
          ans*=26;
          ans+=(columnTitle[i]-'A') + 1;
        }

        return ans;
    }
};