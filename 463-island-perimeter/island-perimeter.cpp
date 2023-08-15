class Solution {
public:
    int perimeter=0;//global variable
    int islandPerimeter(vector<vector<int>>& grid) {
       
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(grid,i,j);
                    break;//because it has been mentioned there is only one island so dfs will cover all the cells connected
                }
            }
        }
        return perimeter;
    }

    void dfs(vector<vector<int>>& grid,int i,int j)
    {        int m=grid.size();
        int n=grid[0].size();
        
     

        if(i<0 || i>=m || j<0 ||j>=n || grid[i][j]==0 )
        {
            perimeter++;
            return;
        }

           if(grid[i][j]==-1)//already visited cell
        return;

        //if none of the above happens it means that neither the current cell is water nor out of bounds and nor is it visited!! therefore mark is visited and call the surrounding cells

        grid[i][j]=-1;    //marking it visited

        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);

    }
};