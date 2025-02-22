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
    TreeNode* recoverFromPreorder(string& traversal) {
        TreeNode* root=NULL;
        vector<pair<TreeNode*, int>> st;
        const int n=traversal.size();
        int temp=0;
        for(int i=0; i<n; i++){
            int x=0;
            while(isdigit(traversal[i])){
                x=10*x+traversal[i]-'0';
                i++;
            }
            TreeNode* node=new TreeNode(x);
            if (temp==0) root=node;
            else{
                while (st.back().second != temp-1) 
                    st.pop_back();
                if (st.back().first->left==NULL)
                    st.back().first->left=node;
                else
                    st.back().first->right=node;
            }
            st.emplace_back(node, temp);
            temp=0;
            while(traversal[i]=='-') temp++, i++;
            i--;
        }
        return root;
    }
};