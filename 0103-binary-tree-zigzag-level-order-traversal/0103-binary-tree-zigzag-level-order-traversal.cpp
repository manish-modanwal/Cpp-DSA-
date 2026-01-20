class Solution {
public:
    void solve(TreeNode* root, vector<vector<int>>& ans)
    {
        if(root == NULL)
            return;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty())
        {
            vector<int> output;

            while(!q.empty())
            {
                TreeNode* node = q.front();
                q.pop();

                if(node == NULL)
                {
                    ans.push_back(output);

                    if(!q.empty())
                        q.push(NULL);

                    break;
                }

                // 🔧 minute fix 1
                output.push_back(node->val);

                // 🔧 minute fix 2
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        solve(root, ans);

        for(int i = 0; i < ans.size(); i++)
        {
            if(i & 1)
                reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};
