class Solution {
public:
    int countSegments(string s) {
        int i =0,count=0;
        while(i<s.length())
        {
            while(i<s.length() && isspace(s[i]))
            i++;
            
            int j=i;
            if(j<s.length())//means we have a char other than space 
              count++;

            while(j<s.length() && !isspace(s[j]))
            j++;
           
         i=j;
        }
        return count;
    }
};