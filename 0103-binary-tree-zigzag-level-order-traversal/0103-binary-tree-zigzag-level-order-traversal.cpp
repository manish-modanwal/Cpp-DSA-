class Solution {
public:
    void solve(TreeNode* root, vector<vector<int>>& ans) {
        if(root == NULL) return;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);   // level marker

        vector<int> output;

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node == NULL) {
                ans.push_back(output);
                output.clear();

                if(!q.empty())
                    q.push(NULL);
            }
            else {
                output.push_back(node->val);

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        solve(root, ans);

        for(int i = 0; i < ans.size(); i++) {
            if(i & 1)
                reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};
