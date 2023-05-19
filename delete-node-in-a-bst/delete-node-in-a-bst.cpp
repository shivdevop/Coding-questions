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
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root==NULL)
        return NULL;
        
        if(root->val==key)
        return helper(root);
        
        TreeNode* dummy=root;

        //if root is not the key we are looking for..we will begin our search

        while(root!=NULL)
        {
            if(root->val> key)
            {
               if(root->left && root->left->val==key)
               {
                   root->left=helper(root->left);
                   break;
               }
               else
               root=root->left;
            }
            else
            {
                if(root->right && root->right->val==key)
               {
                   root->right=helper(root->right);
                   break;
               }
               else
               root=root->right;
            }

        }//end of while
        return dummy;
    }

    //this helper function is goint to accept the node that needs to be deleted
    //and is going to send the node to be attached to the position it was getting deleted

    TreeNode* helper(TreeNode* root) 
    {
        if(root->left==NULL)
        return root->right;
        else if(root->right==NULL)
        return root->left;
        TreeNode* rightNode=root->right;
        TreeNode* rightMostLeftNode=rightMostLeft(root->left);
        rightMostLeftNode->right=rightNode;
        return root->left;
    }

    TreeNode* rightMostLeft(TreeNode* root)
    {    if(root->right==NULL)
         return root;

         return rightMostLeft(root->right);
    } 
};