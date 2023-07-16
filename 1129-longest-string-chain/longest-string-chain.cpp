class Solution {
public:

    static bool comp(string a,string b)
    {return a.length()<b.length();}
   

   bool compare(string a,string b)
   {
       if((b.length()-a.length()) !=1)
       return false;

       int i=0,j=0,count=0;

       while(i<a.length() && j<b.length())
       {
           if(a[i]!=b[j])
           {count++;
           j++;}
           else
           {
           i++;
           j++;
           }
        
       }
       if(count>=2)
       return false;
       else 
       return true;
   }
    

    int longestStrChain(vector<string>& words) {

         int n=words.size();
        vector<int> dp(n,1);//to store the longest sequence
    // vector<int> hash(n);//to store kiska previous kon hai

   sort(words.begin(),words.end(),comp);
  
   int maxi=INT_MIN;
//    int lastdigit_lsc;

    for(int i=0;i<n;i++)
    {
        // hash[i]=i;//for the first time the previous of the element will be element itself 
        for(int prev=0;prev<i;prev++)
        {
            if(compare(words[prev],words[i]) && dp[prev]+1>dp[i])
            {
                dp[i]=dp[prev]+1;
                // hash[i]=prev;
            }
        }
		
		if(dp[i]>maxi)
		{
			maxi=dp[i];
			// lastdigit_lsc=i;
		}
    
    }
     
	//  vector<string> ans;
	//  while(hash[lastdigit_lsc]!=lastdigit_lsc)
	//  {
	// 	 ans.push_back(words[lastdigit_lsc]);
	// 	 lastdigit_lsc=hash[lastdigit_lsc];
	//  }
	//  ans.push_back(words[lastdigit_lsc]);
	// //  reverse(ans.begin(),ans.end()); because order can be anything in the subset !!!!
	 return maxi;  
    }
};