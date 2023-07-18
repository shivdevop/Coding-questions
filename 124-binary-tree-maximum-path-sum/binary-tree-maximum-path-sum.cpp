/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum(TreeNode* root, int &maxi)
    {
      if(root==NULL)
      return 0;
      

      int leftsum=maxSum(root->left,maxi);
      int rightsum=maxSum(root->right,maxi);
      if(leftsum<0)
      leftsum=0;
      if(rightsum<0)
      rightsum=0;

      maxi=max(maxi,root->val + leftsum + rightsum);
   

      return ( max(leftsum,rightsum) + root->val );
    }
     


    int maxPathSum(TreeNode* root) {
    
      int maxi=INT_MIN;
      maxSum(root,maxi);
      return maxi;
        
    }
};