class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        map<char,int> mp;
        int start=0,end=0,maxi=INT_MIN,maxFreqSingleChar=0;//max frequency single char

        for( ; end<s.length(); end++)
        {
            mp[s[end]]++;
            maxFreqSingleChar=max(maxFreqSingleChar,mp[s[end]]);

            while((end-start+1 - maxFreqSingleChar)>k)
            {
                mp[s[start]]--;
                start++;
            }

            maxi=max(maxi,end-start+1);
        }
        return maxi;

        
    }
};