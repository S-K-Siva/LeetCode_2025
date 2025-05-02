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
    int maxLevelSum(TreeNode* root) {
        
        if(!root) return 0;
        queue<TreeNode*> que;
        que.push(root);
        long long maxVal = root->val;
        int level = 1;
        int trackLevel = 1;
        while(!que.empty()){
            queue<TreeNode*> temp;
            long long total = 0;
            while(!que.empty()){
                TreeNode *curr = que.front();
                que.pop();
                total += curr->val;
                if(curr->left){
                    temp.push(curr->left);
                }
                if(curr->right){
                    temp.push(curr->right);
                }
            }
            if(total > maxVal){
                maxVal = total;
                level = trackLevel;
            }
            ++trackLevel;
            que = temp;
        }
        return level;
    }
};