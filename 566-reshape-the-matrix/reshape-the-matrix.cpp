class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {   int row=mat.size();
      int col=mat[0].size();
       if((r*c)!=(row*col))
       return mat;

        vector<vector<int>> reshape(r,vector<int>(c));
        int k=0,l=0;
       for(int i=0;i<r;i++)
       {
           for(int j=0;j<c;j++)
           {
               if(l<col)
               {
                   reshape[i][j]=mat[k][l++];
               }
              else if(l>=col)
               {
                   k++;
                   l=0;
                   reshape[i][j]=mat[k][l++];
               }
           }
       }
       return reshape;
        
    }
};