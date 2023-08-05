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
    void printleft(TreeNode* root,int& sum)
    {    if (root == NULL) {
        return;
    }

    if (root->left && !root->left->left && !root->left->right) {
        // Check if the node is a left leaf node (no left and right children)
        sum += root->left->val;
    }

    printleft(root->left, sum);
    printleft(root->right, sum);
    } 
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        printleft(root,sum);
        return sum;
    }
};