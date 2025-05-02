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
        if(!root) return {};
        queue<TreeNode*> que;
        que.push(root);
        vector<int> result{root->val};
        while(!que.empty()){
            queue<TreeNode*> temp;
            vector<int> row;
            while(!que.empty()){
                TreeNode* curr = que.front();
                que.pop();
                if(!curr) continue;
                if(curr->left){
                    temp.push(curr->left);
                    row.push_back(curr->left->val);
                }
                if(curr->right){
                    temp.push(curr->right);
                    row.push_back(curr->right->val);
                }
            }
            que = temp;
            if(!row.empty())
                result.push_back(row.back());
        }
        return result;
    }
};