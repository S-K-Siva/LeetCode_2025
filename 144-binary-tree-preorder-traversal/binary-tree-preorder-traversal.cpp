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
    vector<int> preorderTraversal(TreeNode* root) {

        stack<TreeNode*> st;
        st.push(root);
        vector<int> result;
        while(!st.empty()){
            TreeNode *current = st.top();
            st.pop();
            if(current == nullptr) continue;
            result.push_back(current->val);

            if(current->right) st.push(current->right);
            if(current->left) st.push(current->left);
        }
        return result;
    }
};