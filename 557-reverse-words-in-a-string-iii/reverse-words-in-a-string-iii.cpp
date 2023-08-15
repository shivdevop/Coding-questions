class Solution {
public:
    string reverseWords(string s) {
      int i=0;
      int n=s.length();
      while(i<n)
      {  
          while(i<n && isspace(s[i]))
          i++;
          int j=i+1;
          while(j<n && !isspace(s[j]))
          j++;
          reverse(s.begin()+i,s.begin()+j);
          i=j+1;
      }  
      return s;
    }
};