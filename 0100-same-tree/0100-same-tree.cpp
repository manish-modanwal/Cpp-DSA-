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
bool isIdentical=true;
    bool Identical(TreeNode* p, TreeNode* q, bool isIdentical)
    {
        if(p==NULL && q==NULL)
        {
            return true;
        }
        if(p==NULL || q==NULL)
        {
            return false;
        }

        if(isIdentical && (p->val!=q->val))
            return false;

        bool ans1=Identical(p->left,q->left,isIdentical); 
        bool ans2=Identical(p->right,q->right,isIdentical);  

        return ans1&&ans2;  
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        return Identical(p,q,isIdentical);

    }
};