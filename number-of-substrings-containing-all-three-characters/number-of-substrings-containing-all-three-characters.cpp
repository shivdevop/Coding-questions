class Solution {
public:
    int numberOfSubstrings(string s) 
    {
     int start=0,end =0,ans=0;
     int n=s.length();
     unordered_map<char,int> mp;
     while(end<n)
     {
       mp[s[end]]++;
       
       if(mp['a']>=1 && mp['b']>=1 && mp['c']>=1)
       { 
           while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1)
           {
           ans+=n-end;
           mp[s[start]]--;
           start++;
           }
       }
       end++;
     }
    return ans; 
    }
};