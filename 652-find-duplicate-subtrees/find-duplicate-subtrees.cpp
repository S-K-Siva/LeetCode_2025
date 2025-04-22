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

    string dfs(TreeNode* root, unordered_map<string,int>& track, set<TreeNode*>& res){
        if(!root) return "#";
        
        string rootVal = to_string(root->val);
        string left = dfs(root->left,track,res);
        string right = dfs(root->right, track ,res);
        string serialize = rootVal + "," + left + "," + right;
        ++track[serialize];
        if(track[serialize] == 2){
            res.insert(root);
        }
        return serialize;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        set<TreeNode*> result;
        unordered_map<string,int> track;

        dfs(root, track, result);
        vector<TreeNode*> res(result.begin(),result.end());
        return res;
    }
};