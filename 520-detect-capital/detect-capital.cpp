class Solution {
public:
    bool detectCapitalUse(string word) {
        int count=0,flag=0;
        if(word[0]>=65 && word[0]<97)
        {
            count=1;
            flag=1;
        }
        else
        count=0;

        for(int i=1;i<word.length();i++)
        {
           if(word[i]>=65 && word[i]<97)
            count++;
        }

        if(count==word.length())
        return true;
        else if(count==0)
        return true;
        else if(count==1 && flag==1)
        return true;
        else 
        return false;

        
    }
};