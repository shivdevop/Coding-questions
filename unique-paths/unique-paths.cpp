class Solution {
public:
//   int f(int row,int col,vector<vector<int>> &dp)
//     {   

//          if(row<0 || col<0)
//         return 0;

//         if(dp[row][col]!=-1)
//         return dp[row][col];

//         if(row==0 && col==0)
//         return 1;

       
//         int up=f(row-1,col,dp);
//         int left=f(row,col-1,dp);
//         return dp[row][col]=up + left;
//     }

//  int uniquePaths(int m, int n)
//     {
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         int ans=f(m-1,n-1,dp);
//         return ans;
        
//     }


//TABULAR METHOD

 int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        //DECLARE BASE CASES 
        dp[0][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                dp[i][j]=1;
                else
                {
                 int bottom=0,right=0;
                if(i>0) 
                 bottom=dp[i-1][j];
                if(j>0)
                 right=dp[i][j-1];
                dp[i][j]=bottom+right;
                }
            }
        }

        return dp[m-1][n-1];
        
    }
};