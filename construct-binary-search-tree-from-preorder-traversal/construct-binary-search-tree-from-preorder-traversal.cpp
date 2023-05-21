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
     TreeNode* buildTree(vector<int> preorder, int prestart,int preend, vector<int> inorder, int instart, int inend, map<int,int> mpp)
     { 
         if(prestart>preend || instart> inend )
         return NULL;

        TreeNode* root = new TreeNode(preorder[prestart]);
       
       int inroot=mpp[root->val];
       int numsleft=inroot-instart;

       root->left=buildTree(preorder,prestart + 1,prestart+ numsleft,inorder,instart,inroot-1,mpp);

       root->right=buildTree(preorder,prestart+numsleft+1,preend,inorder, inroot+1,inend,mpp);
    
      return root;
     }

    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
       //since i know this is a bst therefore i can sort any traversal given to make it an inorder traversal
       //and then i can combine any given traversal with inorder traversal to generate a binary tree 
       //that binary tree itself will be our desired binary search tree
        vector<int> inorder(preorder);
        sort(inorder.begin(),inorder.end());

        //we will create a map of inorder values and their indexes
        map<int,int> mpp; 
        for(int i=0;i<inorder.size();i++)
        mpp[inorder[i]]=i;

        //now we have to create a root

        TreeNode* root=buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mpp);

        return root; 

   }

};