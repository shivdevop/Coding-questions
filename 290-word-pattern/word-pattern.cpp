class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
      map<char,string> mp1;
      map<string,char> mp2;
      int i=0,k=0,j;
      while(i<s.length())
      {
          while(isspace(s[i]))
          i++;
          if(i>=s.length())
          break;

          j=i+1;
          
          while(j<s.length() && !isspace(s[j]))
          j++;

          string str=s.substr(i,j-i);
          char c=pattern[k];
          if(mp1.find(c)==mp1.end() && mp2.find(str)==mp2.end())
         { mp1[c]=str;
           mp2[str]=c;}
          else if(mp1[c]!=str || mp2[str]!=c) //if the char exists in the map, we will check whether the current string matches with the one that character is currently storing as its value 
          {
               
                 return false;
          }
          k++;
          i=j+1;
      }
      return k==pattern.length() ;
    }
};