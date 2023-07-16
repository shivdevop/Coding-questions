class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
      
       int n=arr.size();
        vector<int> dp(n,1);//to store the longest sequence
    vector<int> hash(n);//to store kiska previous kon hai

   sort(arr.begin(),arr.end());
  
   int maxi=INT_MIN;
   int lastdigit_lds;

    for(int i=0;i<n;i++)
    {
        hash[i]=i;//for the first time the previous of the element will be element itself 
        for(int prev=0;prev<i;prev++)
        {
            if(arr[i]%arr[prev]==0 && dp[prev]+1>dp[i])
            {
                dp[i]=dp[prev]+1;
                hash[i]=prev;
            }
        }
		
		if(dp[i]>maxi)
		{
			maxi=dp[i];
			lastdigit_lds=i;
		}
    
    }
     
	 vector<int> ans;
	 while(hash[lastdigit_lds]!=lastdigit_lds)
	 {
		 ans.push_back(arr[lastdigit_lds]);
		 lastdigit_lds=hash[lastdigit_lds];
	 }
	 ans.push_back(arr[lastdigit_lds]);
	//  reverse(ans.begin(),ans.end()); because order can be anything in the subset !!!!
	 return ans;
 
    }
};