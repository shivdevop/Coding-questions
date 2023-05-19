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
void inorder(TreeNode* root, vector<int> & in)
  {
      if(root==NULL)
      return;
      
      inorder(root->left,in);
      in.push_back(root->val);
      inorder(root->right, in);
  }

    bool isValidBST(TreeNode* root) {
        // if(root==NULL)
        // return true;
        // else if(root->right==NULL && root->left==NULL)
        // return true;
        // else if(root->left==NULL && root->right->val>root->val)
        // return true;
        // else if(root->right==NULL && root->left->val<root->val)
        // return true;
        // else if(((root->right)&&(root->right->val>root->val)) && ((root->left) && (root->left->val<root->val)))
        // return true;
        // else 
        // return false;
    

        // return (isValidBST(root->left) && isValidBST(root->right)); 

      vector<int> in;
     inorder(root,in);
     
     for(int i=1;i<in.size();i++)
     if(in[i]<=in[i-1])
     return false;
   
     return true;   
    }
};