class Solution {
public:
    string reverseWords(string s) {
    //i for traversing over spaces
    //j for traversing over  char
    string res;
    int n=s.length();
    int i=0;
    while(i<n)
    {
        while(isspace(s[i]))
        i++;//i will stop at the first char of next substr
        
        if(i>=n)
        break;

        int j=i+1;

        while(j<n && !isspace(s[j]))
        j++;  //j will stop at the first space after substr


        string str=s.substr(i,j-i);
        if(res.empty())
        res=str;
        else
        res=str+" "+res;

        i=j+1; 

    }
    return res;

    }
}; 