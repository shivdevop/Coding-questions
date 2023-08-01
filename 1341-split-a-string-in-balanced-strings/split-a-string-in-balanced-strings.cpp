class Solution {
public:
    int balancedStringSplit(string s) {
      //since the entire string is balanced, if we find a substring which is balanced, then the remaining part has to be balance!!!!bcoz if it wouldnt be then the entire string would become unbalanced !!!
      int r=0,l=0,count=0;
      for(int i=0;i<s.length();i++)
      {
         if(s[i]=='L')
         l++;
         else
         r++;

         if(l==r)
         {count++;
         l=0;
         r=0;}
      }  
      return count;
    }
};