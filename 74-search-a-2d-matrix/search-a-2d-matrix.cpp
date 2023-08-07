class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int row=matrix.size();
        int  column=matrix[0].size();//important
        
        
        int c=0,r=row-1;
        while(r>=0 && c<=(column-1))
        {
            if(target==matrix[r][c])
                return true;
            else if(target > matrix[r][c])
                c++;
            else
                r--;
            
        }
        return false;
    }
};