class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
     int row=matrix.size();
     int col=matrix[0].size(); 
    vector<int> rowdp(row,-1);
    vector<int> coldp(col,-1);
    for(int i=0;i<row;i++)
    {
     for(int j=0;j<col;j++)
      {
        if(matrix[i][j]==0)
        { 
          rowdp[i]=0;
          coldp[j]=0;
        } 

      }
    }

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++){
            if(rowdp[i]==0 || coldp[j]==0)
            matrix[i][j]=0;
        }
    }
    }
};