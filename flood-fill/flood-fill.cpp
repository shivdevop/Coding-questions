class Solution {
public:
    
    void dfs(int row,int col,vector<vector<int>>& image,vector<vector<int>>& ans, int dr[], int dc[], int initial, int newcolor,int m, int n)
    {
    //  int m=image.size();//no. of rows 
    // int n=image[0].size();//no. of cols
      ans[row][col]=newcolor;//node that is to be visited through dfs after the 4 directional and same color check has to be updated first.

      for(int i=0;i<4;i++)
      {
         int nrow= row + dr[i];
         int  ncol=col + dc[i];
        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol]==initial && ans[nrow][ncol]!=newcolor)//such a big mistake i was committing initially. i was using the condition image[nrow][ncol]!=newcolor which was giving me a runtime error bcoz this situation was always going to be true and the dfs would run forever
        {
        dfs(nrow,ncol,image,ans,dr,dc,initial,newcolor,m,n);
        }
      }

    }//end of dfs function 
    
    
    
    
    
    
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
      int m=image.size();//no. of rows 
    int n=image[0].size();//no. of cols
        vector<vector<int>> ans=image;
        int initial=image[sr][sc];

        int dr[]={-1,0,+1,0};//change in row for 4 directional row no.
        int dc[]={0,+1,0,-1};//change in column for 4 directional col no.

     dfs(sr,sc,image,ans,dr,dc,initial,color,m,n);

     return ans;
}
};