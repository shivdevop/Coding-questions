class Solution {
public:
    void f(int index,string digits,vector<string> map,string ls,vector<string> &ans)
    {
       if(index>=digits.size())
       {
           ans.push_back(ls);
           return;
       }

       int number=digits[index]-'0';//'2'-'0'=2
       string curr=map[number];

       for(int i=0;i<curr.size();i++)
       {      char ch = curr[i];
             string str(1, ch);
           f(index+1,digits,map,ls+str,ans);
       }

    }
   
   //basically in this question we are combining solutions from multiple strings so it becomes important for us because here we deal with recursion along with loops !!!!
    vector<string> letterCombinations(string digits) 
    { 
      vector<string> ans;
      if(digits.size()==0)
       return ans;
      string ls="";
       vector<string> map={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
       f(0,digits,map,ls,ans);
       return ans;

        
    }
};