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

    int findDepth(TreeNode* root){
        if(!root) return 0;
        return 1 + max(findDepth(root->left),findDepth(root->right));
    }
    TreeNode* dfs(TreeNode* root, int depth, int length){
        if(!root) return nullptr;
        if(length == depth-1) return root;
        TreeNode *left,*right;
        left = dfs(root->left,depth,length+1);
        right = dfs(root->right,depth,length+1);
        if(left && right) return root;
        return left ? left : right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int depth = findDepth(root);
        return dfs(root,depth,0);
    }
};