/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
    //two times traversal and maintaing a vector to store ancestors;
    vector<TreeNode*> temp;
    TreeNode* ans;
    TreeNode* temproot=root;
    while(root!=NULL)
    {
      if(root==p){temp.push_back(root);
      break;}
      else if (root->val > p->val)
      {
        temp.push_back(root);
        root=root->left;
      }
      else
      {
          temp.push_back(root);
          root=root->right;
      }

    }//end of while

    root=temproot;
    int i=0;
    while(i<temp.size() && root!=NULL)
    {
        if(temp[i]->val!=root->val)
        {
            ans=temp[i-1];
            break;
        }
        if(root==q){ans=temp[i];break;}
        else if(root->val>q->val)
        root=root->left;
        else
        root=root->right;
        i++;
    }
    if(ans==NULL)
    ans=temp[temp.size()-1];
    return ans;

    // vector<TreeNode*> temp;
    // TreeNode* ans = nullptr;
    // TreeNode* tempRoot = root;
    
    // while (root != nullptr) {
    //     temp.push_back(root);
        
    //     if (root == p || root == q) {
    //         break;
    //     } else if (root->val > p->val) {
    //         root = root->left;
    //     } else {
    //         root = root->right;
    //     }
    // }
    
    // int i = 0;
    // while (i<temp.size() && temp[i] == root) {
    //     ans = temp[i];
        
    //     if (root == q || temp[i] == q) {
    //         break;
    //     } else if (root->val > q->val) {
    //         root = root->left;
    //     } else {
    //         root = root->right;
    //     }
        
    //     i++;
    // }
    
    // return ans;
}
};