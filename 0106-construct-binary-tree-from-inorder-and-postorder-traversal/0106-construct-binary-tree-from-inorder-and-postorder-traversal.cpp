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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int &postIndex,int inStart, int inEnd)
    {
        if(postIndex<0 || inStart >inEnd)
        {
            return NULL;
        }

        TreeNode* root =new TreeNode(postorder[postIndex]);
        postIndex--;
        int InIndex;
        for(int i=inStart;i<=inEnd;i++)
        {
            if(root->val==inorder[i])
            {
                InIndex=i;
                break;
            }
        }
        root->right=solve(inorder,postorder,postIndex,InIndex+1,inEnd);
        root->left=solve(inorder,postorder,postIndex,inStart,InIndex-1);
        

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex=postorder.size()-1;
        TreeNode* T =solve(inorder,postorder,postIndex,0,inorder.size()-1);

        return T;
    }
};