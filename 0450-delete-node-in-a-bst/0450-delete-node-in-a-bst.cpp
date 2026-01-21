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



    int FindMax(TreeNode*root)
    {
        if(root==NULL)
        {
            return -1;
        }

        while(root->right!=NULL)
        {
            root=root->right;

        }
        return root->val;
    }

    TreeNode* deleteNode(TreeNode* root, int target) {
        if(root==NULL)
        {
            return NULL;
        }

        if(root->val==target)
        {
            if(root->left==NULL && root->right==NULL)
            {
                delete root;
                return NULL;
            }
            else if(root->left==NULL && root->right!=NULL)
            {
                TreeNode* child= root->right;
                delete root;
                return child;
            }
             else if(root->left!=NULL && root->right==NULL)
            {
                TreeNode* child= root->left;
                delete root;
                return child;
            }else{
                int Predessesor= FindMax(root->left);
                root->val=Predessesor;
                root->left=deleteNode(root->left,Predessesor);

                return root;
            }
        }
        else if(root->val<target)
        {
            root->right=deleteNode(root->right,target);
        }else if(root->val>target)
        {
            root->left=deleteNode(root->left,target);
        }

        return root;
    }
};