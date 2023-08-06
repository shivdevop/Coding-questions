class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        
        for(auto ch:s)
        mp[ch]++;

        int count=0;
        int maxi=0;
        int flag=0;
        for(auto it:mp)
        {   
            if(it.second%2==0)
            count+=it.second;
            else if(it.second%2)
            {count+=it.second-1;flag=1;}
        }      
        if(flag==1)
        return count+1;
        return count;
    }
};