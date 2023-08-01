class Solution {
public:
    int maximum69Number (int num)
    {
         string s=to_string(num);//integer to string directly conversion
         for(int i=0;i<s.length();i++)
         {
             if(s[i]=='6')
            { s[i]='9';
            break;}
         }       
         num=stoi(s);//direct conversion from string to number!!!!
         return num;



    }
};