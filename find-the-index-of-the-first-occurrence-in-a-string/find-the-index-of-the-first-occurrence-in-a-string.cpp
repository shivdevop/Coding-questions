class Solution {
public:
    int strStr(string haystack, string needle)
    {

        for(int i=0;i<haystack.length();i++)
        {
            if(haystack[i]==needle[0])
            {   int initial=i;
                int j;
                for( j=1;j<needle.length();j++)
                {
                    i++;
                    if(haystack[i]!=needle[j])
                    break;

                }
                if(j==needle.length())
                return initial;
                else 
                i=initial;
            }

        }
        return -1;
        
    }
};