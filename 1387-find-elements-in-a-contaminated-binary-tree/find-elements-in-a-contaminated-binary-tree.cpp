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
class FindElements {
public:
    TreeNode* Root;

    FindElements(TreeNode* root) {
        if(root){
            root->val = 0;
        }
        this->Root = root;

    }
    
    bool findNode(TreeNode* node, int target){
        if(!node) return false;
        if(node->val == target) return true;
        if(node->left != nullptr){
            node->left->val = node->val * 2 + 1;
        }
        if(node->right != nullptr){
            node->right->val = node->val * 2 + 2;
        }
        if(findNode(node->left,target)) return true;
        if(findNode(node->right,target)) return true;
        return false;
    }

    bool find(int target) {
        return findNode(Root,target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */