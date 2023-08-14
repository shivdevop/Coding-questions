class Solution {
public:
    void f(int i,vector<string> &ans)
    {
      if(i%3==0 && i%5==0)
      ans.push_back("FizzBuzz");
      else if(i%3==0)
      ans.push_back("Fizz");
      else if(i%5==0)
      ans.push_back("Buzz");
      else
      ans.push_back(to_string(i));
    }
    vector<string> fizzBuzz(int n) {
      vector<string> ans;
     for(int i=1;i<=n;i++)
     f(i,ans);

     return ans;
    }
};