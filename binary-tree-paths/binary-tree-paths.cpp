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

    vector<string> binaryTreePaths(TreeNode* root) 
    {
       vector<string> ans;
      string currentPath="";
      if(root==NULL)
      return ans;
      currentPath=to_string(root->val);
      if(!root->left && !root->right)
      {
        
          ans.push_back(currentPath);
          return ans;
      }

      if(root->left)
      dfs(root->left,currentPath,ans);
      if(root->right)
      dfs(root->right,currentPath,ans);

      return ans;
    }
         void dfs(TreeNode* node,string currentPath,vector<string> &ans)
     {
          currentPath+="->"+to_string(node->val);

          if(!node->left && !node->right)
          
          {  
              ans.push_back(currentPath);
              return;
          }
         
         if(node->left)
        dfs(node->left,currentPath,ans);

          if(node->right)
        dfs(node->right,currentPath,ans);

     }
};