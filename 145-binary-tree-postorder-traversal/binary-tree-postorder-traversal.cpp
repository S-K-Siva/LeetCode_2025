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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s1,s2;
        s1.push(root);

        while(!s1.empty()){
            TreeNode *current = s1.top();
            s1.pop();
            s2.push(current);
            if(current == nullptr) continue;
            if(current->left){
                s1.push(current->left);
            }
            if(current->right){
                s1.push(current->right);
            }
        }

        vector<int> result;
        while(!s2.empty()){
            if(s2.top() == nullptr){
                s2.pop();
                continue;
            }
            result.push_back(s2.top()->val);
            s2.pop();
        }
        return result;
    }
};