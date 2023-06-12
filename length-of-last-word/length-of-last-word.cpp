class Solution {
public:
    int lengthOfLastWord(string s) {
    
     int length;    
     int n=s.length();
     int i=0,j;
     while(i<n)
     {
    
     while(s[i]==' ')
     i++;//end of while
    
     if(i>=n)
     break;
    
     j=i+1;
     while(j<n && s[j]!=' ')
     j++;//end of while
    
     length=j-i;
    
     i=j+1;  
     }//closing of first while
    
     return length ;
    
   }
};