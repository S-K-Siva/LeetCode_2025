/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    void solve(Node* root, int& maxi, int len) {
        if (!root) return;

        if (root->children.empty()) {
            maxi = max(maxi, len);
        }

        for (auto child : root->children) {
            solve(child, maxi, len + 1);
        }
    }

    int maxDepth(Node* root) {
        if (!root) return 0;
        int res = 0;
        solve(root, res, 1);
        return res;
    }
};
