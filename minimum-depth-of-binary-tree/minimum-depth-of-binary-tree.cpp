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
    int minDepth(TreeNode* root) {
        
        if(root==NULL)
        return 0;
        if(root->left==NULL && root->right==NULL)
        return 1;
        int lheight=1000000,rheight=100000;
        if(root->left)
         lheight=minDepth(root->left);
        if(root->right)
         rheight=minDepth(root->right);

        return 1+min(lheight,rheight);
    }
};