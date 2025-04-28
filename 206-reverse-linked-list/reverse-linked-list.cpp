/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void solve(ListNode* node, queue<int>& que){
        if(!node) return;
        que.push(node->val);
        solve(node->next,que);
        node->val = que.front();
        que.pop(); 
    }
    ListNode* reverseList(ListNode* head) {
        queue<int> que;
        solve(head,que);
        return head;
    }
};