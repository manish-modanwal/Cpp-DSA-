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
int d=0;
    int maxDepth(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }

     int left=   maxDepth(root->left);
     int right=   maxDepth(root->right);
       int currd=left+right;
        d=max(d,currd);
        return max(left, right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {

        if(root==NULL)
         return  0;
       maxDepth(root);

        return d;
    }
};