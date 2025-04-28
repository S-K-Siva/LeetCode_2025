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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *evenList = new ListNode(-1);
        ListNode *oddList = new ListNode(-1);
        ListNode *oddTemp,*evenTemp;
        oddTemp = oddList;
        evenTemp = evenList;
        ListNode *temp;
        temp = head;
        int index = 1;
        while(temp){
            if(index%2){
                oddTemp->next = new ListNode(temp->val);
                oddTemp = oddTemp->next;
            }else{
                evenTemp->next = new ListNode(temp->val);
                evenTemp = evenTemp->next;
            }
            index++;
            temp = temp->next;
        }
        oddTemp->next = evenList->next;
        return oddList->next;
    }
};