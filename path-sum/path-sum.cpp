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
 
//  if(root==NULL)
//         return false;
        
//         if(!root->left && !root->right && root->val==targetSum)//if its a leaf node 
//          return true;
         
//          if(root->left)
//          hasPathSum(root->left,targetSum-root->val);
//          if(root->right)
//          hasPathSum(root->right,targetSum-root->val);

//         return false;  --> ye krne se har baar false return ho jayega

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) 
    {

        if(root==NULL)
        return false;
        
        if(!root->left && !root->right )//if its a leaf node 
         return root->val==targetSum;

         bool output;
         
         if(root->left)
         output=hasPathSum(root->left,targetSum-root->val);
         if(root->right)
         output=output || hasPathSum(root->right,targetSum-root->val);

        return output; 
    }
};