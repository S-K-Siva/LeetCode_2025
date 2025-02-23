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
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder, int& index, int postStart, int postEnd) {
        if (index >= preorder.size() || postStart > postEnd) return nullptr;

        TreeNode* node = new TreeNode(preorder[index]);
        ++index;
        if (postStart == postEnd || index >= preorder.size()) return node;

        int pos = postStart;
        for (; pos <= postEnd; ++pos) {
            if (postorder[pos] == preorder[index]) break;
        }

        node->left = solve(preorder, postorder, index, postStart, pos);
        node->right = solve(preorder, postorder, index, pos + 1, postEnd - 1);

        return node;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int index = 0;
        return solve(preorder, postorder, index, 0, postorder.size() - 1);
    }
};