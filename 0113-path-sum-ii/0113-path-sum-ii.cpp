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
    vector<vector<int>> ans;
    void path(TreeNode* root, int targetSum,vector<int>&output)
    {
        if(root==NULL)
            return;

       output.push_back(root->val);

       if(root->left==NULL && root->right==NULL && targetSum == root->val)
       {
          ans.push_back(output);
       }

       path(root->left,targetSum-root->val,output);
       path(root->right,targetSum-root->val,output);


       output.pop_back();



    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>output;
        path(root,targetSum,output);
        return ans;
    }
};