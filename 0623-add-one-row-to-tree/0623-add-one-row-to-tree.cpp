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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        

        if(depth==1)
        {
           TreeNode* newRoot= new TreeNode(val) ;
           newRoot->left = root;
           return newRoot;
        }

        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);

        int currdepth=1;

        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();

            if(node==NULL)
            {
               currdepth++;
               if (!q.empty()) q.push(NULL);
            }
            else{
                if(currdepth==depth-1)
                {
                    TreeNode* oldleft=node->left;
                    TreeNode* oldright=node->right;

                     node->left = new TreeNode(val);
                     node->right = new TreeNode(val);

                    node->left->left = oldleft;
                    node->right->right = oldright;

                }
                else{
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }
        }
        return root;
        
    }
};