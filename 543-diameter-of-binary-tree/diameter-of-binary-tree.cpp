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
    int diameter = INT_MIN;
    int solve(TreeNode* root){
        if(root == nullptr) return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        diameter = max(diameter, left + right);
        return 1+max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) { 
        int lh = solve(root->left);
        int rh = solve(root->right);
        return max(lh + rh, diameter);
        
    }
};