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
    vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;

    vector<TreeNode*> v;
    queue<TreeNode*> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == NULL) {
            v.push_back(NULL);
            if (!q.empty()) q.push(NULL);
        } else {
            v.push_back(node);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    // traverse from back
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] == NULL && i > 0 && v[i - 1] != NULL) {
            ans.push_back(v[i - 1]->val);
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

};