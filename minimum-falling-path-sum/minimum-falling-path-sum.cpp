class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
      int m=matrix.size();
     vector<vector<int>> dp(m,vector<int>(m,-1));

     //define all base cases 
     for(int j=0;j<m;j++)
     dp[m-1][j]=matrix[m-1][j];
    
    for(int i=m-2;i>=0;i--)
     {
         for(int j=m-1;j>=0;j--)
         {   int rightdiag=INT_MAX,leftdiag=INT_MAX;
             int down=matrix[i][j]+dp[i+1][j];
             if(j+1 <m)
              rightdiag=matrix[i][j]+dp[i+1][j+1];
             if(j-1 >=0)
             leftdiag =matrix[i][j]+dp[i+1][j-1];
             dp[i][j]=min(min(down,rightdiag),leftdiag);
          }

     }
     int ans=INT_MAX;
     for(int i=0;i<m;i++)
     {
         ans=min(ans,dp[0][i]);
     }
     return ans;    
    }
};