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
    int getMinimumDifference(TreeNode* root) {
        
        vector<int> inorder;
        f(root,inorder);
        int mindiff=INT_MAX;
        for(int i=0;i<inorder.size()-1;i++)
        {
          if(abs(inorder[i+1]-inorder[i]) < mindiff)
          mindiff=abs(inorder[i+1]-inorder[i]);
        }
        return mindiff;
    }

    void f(TreeNode* root,vector<int>& inorder)
    {
        if(root==NULL)
        return;

        f(root->left,inorder);
        inorder.push_back(root->val);
        f(root->right,inorder);

    }

};