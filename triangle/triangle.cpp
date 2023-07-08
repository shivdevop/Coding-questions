class Solution {
public:
    
// int f(int i,int j,vector<vector<int>> triangle,vector<vector<int>> &dp)
// {
//     //base case 
//     if(i==triangle.size()-1)
//     return triangle[triangle.size()-1][j];

//     //no out of bounds case 
    
//     if(dp[i][j]!=-1 )
//     return dp[i][j];

//     int down=triangle[i][j]+f(i+1,j,triangle,dp);
//     int diag=triangle[i][j]+f(i+1,j+1,triangle,dp);

//     return dp[i][j]=min(down,diag);
    

// }

//     int minimumTotal(vector<vector<int>>& triangle) {
//    int m=triangle.size();
//      vector<vector<int>> dp(m,vector<int>(m,-1));
//      int ans=f(0,0,triangle,dp);
//      return ans;    
//     }
    

  int minimumTotal(vector<vector<int>>& triangle) {
    int m=triangle.size();
     vector<vector<int>> dp(m,vector<int>(m,-1));

     //define all base cases 
     for(int j=0;j<m;j++)
     dp[m-1][j]=triangle[m-1][j];


     for(int i=m-2;i>=0;i--)
     {
         for(int j=i;j>=0;j--)
         {
             int down=triangle[i][j]+dp[i+1][j];
             int diag=triangle[i][j]+dp[i+1][j+1];
             dp[i][j]=min(down,diag);
          }

     }
    return dp[0][0];
    }
};