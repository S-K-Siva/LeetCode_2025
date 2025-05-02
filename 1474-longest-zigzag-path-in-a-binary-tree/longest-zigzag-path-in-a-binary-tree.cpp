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
    int maxVal = 0;
    void helper(TreeNode* root, char ch, int cnt){
        if(!root) return;
        maxVal = max(maxVal, cnt);
        if(ch == 'L'){
            if(root->right)
                helper(root->right, 'R', cnt+1);
            return;
        }else{
            if(root->left)
                helper(root->left, 'L',cnt+1);
        }
    }
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        helper(root->left,'L',1);
        helper(root->right,'R',1);
        longestZigZag(root->left);
        longestZigZag(root->right);
        return maxVal;
    }
};