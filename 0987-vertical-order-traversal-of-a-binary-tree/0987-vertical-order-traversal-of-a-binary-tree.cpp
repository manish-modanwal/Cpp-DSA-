class Solution {
public:
    void solve(TreeNode* root,int row, int col, map<int, vector<pair<int,int>>>& mp)
    {
        if(root == NULL)
            return;

        mp[col].push_back({row,root->val});

        solve(root->left,row+1, col - 1, mp);
        solve(root->right, row+1, col + 1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int,int>>> mp;
        vector<vector<int>> ans;

        solve(root, 0,0, mp);   // 🔥 missing call fixed


        for(auto &it : mp) {
            vector<pair<int,int>>& vec = it.second;

            sort(vec.begin(),vec.end());

            vector<int>colval;
            for(auto & val:vec)
            {
                colval.push_back(val.second);
            }

            ans.push_back(colval);
        }
        return ans;
    }
};
