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
    void inorder(TreeNode* root, int& cnt, int rootValue){
        if(!root) return;
        if(root->val >= rootValue){
            cnt++;
            rootValue = root->val;
        }
        inorder(root->left, cnt , rootValue);
        inorder(root->right, cnt, rootValue);
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int cnt = 0;
        inorder(root,cnt,root->val);
        return cnt;
    }
};