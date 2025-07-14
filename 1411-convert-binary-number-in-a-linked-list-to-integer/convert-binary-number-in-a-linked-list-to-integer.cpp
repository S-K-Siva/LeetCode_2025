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
private:
    int exp = 0;
public:
    
    int getDecimalValue(ListNode* head) {
        if(head == nullptr) return 0;
        int value = getDecimalValue(head->next);
        if(head->val == 1){
            value += pow(2,exp);
        }
        exp++;
        return value;
        //without recursion
        // ListNode *result;
        // result = new ListNode(-1);

        // while(head != nullptr){
        //     ListNode *newNode;
        //     newNode = new ListNode(head->val);
        //     newNode->next = result;
        //     result = newNode;
        //     head = head->next;
        // }
        
        // int exp = 0;
        // int res = 0;
        // while(result != nullptr){
        //     if(result->val == -1) break;
        //     if(result->val == 1){
        //         res += pow(2,exp);
        //     }
        //     exp++;
        //     result = result->next;
        // }
        // return res;
    }
};