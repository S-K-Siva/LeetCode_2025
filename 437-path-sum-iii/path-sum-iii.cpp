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

    int solve(TreeNode* root, long long targetSum){
        if(!root) return 0;
        int cnt = 0;
        if(targetSum == root->val){
            cnt++;
        }

        cnt += solve(root->left, targetSum - root->val);
        cnt += solve(root->right, targetSum - root->val);

        return cnt;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return solve(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};