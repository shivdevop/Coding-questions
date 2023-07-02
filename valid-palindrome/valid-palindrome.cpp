class Solution {
public:
    bool isPalindrome(string s) 
    {
    string res="";
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        char ch=s[i];
        if(isdigit(ch))
        res=res+ch;
        else if (isalpha(ch) && islower(ch))
        res+=ch;
        else if(isalpha(ch) && isupper(ch))
        res+= tolower(ch);
    }

    int i=0,j=res.length()-1;
    while(i<=j)
    {
        if(res[i]!=res[j])
        return false;

        i++;
        j--;
    }
    return true;
}
};