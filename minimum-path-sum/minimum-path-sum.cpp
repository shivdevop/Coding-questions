class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
         int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        //DECLARE BASE CASES 
        dp[0][0]=grid[0][0];

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                dp[i][j]=grid[i][j];
                else
                {
                 int bottom=-1,right=-1;
                 if(i>0)
                 bottom=dp[i-1][j]+grid[i][j];
                if(j>0)
                 right=dp[i][j-1]+grid[i][j];
                
                if(bottom!=-1 && right!=-1)
                dp[i][j]=min(bottom,right);
                else if(bottom!=-1)
                dp[i][j]=bottom;
                else
                dp[i][j]=right;
                }
            }
        }

        return dp[m-1][n-1];
        
    }
    
};