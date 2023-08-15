class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char,int> mp;
        vector<string> ans;
        for(char c:"qwertyuiop")
        mp[c]=1;
        for(char c:"QWERTYUIOP")
        mp[c]=1;
        for(char c:"asdfghjkl")
        mp[c]=2;
        for(char c:"ASDFGHJKL")
        mp[c]=2;
        for(char c:"zxcvbnm")
        mp[c]=3;
        for(char c:"ZXCVBNM")
        mp[c]=3;

        for(int i=0;i<words.size();i++)
        {
            string s=words[i];
            int flag=0;
            int row=mp[s[0]];
            for(char c:s)
            {
              if(mp[c]!=row)
              {
                  flag=1;
                  break;
              }
            }
            if(flag==0)
            ans.push_back(words[i]);
            
        }
      return ans;
    }
};