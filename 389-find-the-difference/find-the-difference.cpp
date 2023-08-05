class Solution {
public:
    char findTheDifference(string s, string t) {
    // sort(t.begin(),t.end());
    // int i;
    // for( i=0;i<s.length();i++)
    // {
    //     if(s[i]!=t[i])
    //     return t[i];
    // }
    // return t[i];
    // }
      char result = 0;
    
    for (char ch : s) {
        result ^= ch;
    }
    
    for (char ch : t) {
        result ^= ch;
    }
    
    return result;
    }
};