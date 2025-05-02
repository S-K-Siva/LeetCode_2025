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
    void inorder(TreeNode* root, vector<int>& arr){
        if(!root) return;
        if(root->left == nullptr && root->right == nullptr)
        {
            arr.push_back(root->val);
        }
        inorder(root->left, arr);
        inorder(root->right,arr);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafNodes1, leafNodes2;
        inorder(root1, leafNodes1);
        inorder(root2, leafNodes2);
        return leafNodes1 == leafNodes2;
    }
};