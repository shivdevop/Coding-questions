#include<bits/stdc++.h>
class Solution {
public:
    bool checkVowel(char ch)
    {
        string s = "aeiouAEIOU";
        cout<<s.find(ch)<<" ";//s.find(ch) returns the index of the char in the string and if the char is not present in the string then the index is equivalent to string::npos 
        return s.find(ch) != string::npos;
        
    }
    
    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            while (i < j && !checkVowel(s[i]))
                i++;
            while (i < j && !checkVowel(s[j]))
                j--;
            
            if (i < j)
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};
