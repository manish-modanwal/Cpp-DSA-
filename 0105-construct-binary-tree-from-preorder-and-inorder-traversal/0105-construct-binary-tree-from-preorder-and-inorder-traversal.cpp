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

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int & preIndex,int InStart,int InEnd )
    {
        if(preIndex >=preorder.size() || InStart>InEnd)
        {
            return NULL;
        }
        int inIndex;
        TreeNode* root= new TreeNode(preorder[preIndex]);
        preIndex++;


        for(int i=InStart;i<=InEnd;i++)
        {
            if (inorder[i] == root->val) {
                inIndex = i;
                break;
            }
        }

        root->left=solve(preorder,inorder,preIndex,InStart,inIndex-1);
        root->right=solve(preorder,inorder,preIndex,inIndex+1,InEnd);


        return root;


    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {   int preIndex = 0;
        TreeNode* T=solve(preorder,inorder, preIndex ,0, inorder.size() - 1);
        return T;
    }
};