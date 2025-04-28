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

    void solve(ListNode* node, stack<int>& st, int& maxVal, int ind, int middle){
        if(!node) return;
        if(ind < middle){
            st.push(node->val);
        }else{
            maxVal = max(maxVal , node->val + st.top());
            st.pop();
        }
        solve(node->next,st,maxVal,ind+1,middle);
    }
    int pairSum(ListNode* head) {
        int n = 0;
        ListNode *temp;
        temp = head;
        while(temp){
            ++n;
            temp = temp->next;
        }
        int middle = n/2;
        stack<int> st;
        int maxi = INT_MIN;
        solve(head,st,maxi,0,middle);
        return maxi;
    }
};