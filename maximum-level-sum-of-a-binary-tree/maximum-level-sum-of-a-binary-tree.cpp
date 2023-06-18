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
    int maxLevelSum(TreeNode* root) {
  
 
 if(root==NULL)
        return -1;
        //we can use level order traversal using queue 
        //on ending a level, we can add the pair of level and sum either to a vector or a map
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int sum=0;
        int level=0;
        // vector<pair<int,int>> v;
        int ans=0;
        int maxi=INT_MIN;
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp!=NULL)
            sum+=temp->val;
            if(temp==NULL)
            { if(sum>maxi)
               {
                   maxi=sum;
                   ans=level;
               }
            //  v.push_back({level,sum});
              level++;
              sum=0;
              if(!q.empty())
              q.push(NULL);
            }
            else 
            {
                if(temp->left !=NULL )
            q.push(temp->left);
             if(temp->right !=NULL)
            q.push(temp->right);
            }
        }//end of while
        // sort(v.begin(),v.end(),comp);
        // int ans=v[0].first;
        return ans+1;


    }
};