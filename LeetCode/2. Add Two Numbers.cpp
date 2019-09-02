/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *tmp = new ListNode(l1->val + l2->val);
        ListNode *solution = tmp;
        
        l1 = l1->next;
        l2 = l2->next;
        
        int rem = 0;
        if(tmp->val >= 10)
            rem = 1, tmp->val -= 10;
        
        while(l1 != NULL || l2 != NULL) {
            if(l1 == NULL) {
                tmp->next = new ListNode(l2->val + rem);
                tmp = tmp->next;
            } else if(l2 == NULL) {
                tmp->next = new ListNode(l1->val + rem);
                tmp = tmp->next;
            } else {
                tmp->next = new ListNode(l1->val + l2->val + rem);
                tmp = tmp->next;
            }
            
            rem = 0;
            if(tmp->val >= 10)
                rem = 1, tmp->val -= 10;
            
            if(l1 != NULL)
                l1 = l1->next;
            if(l2 != NULL)
                l2 = l2->next;
        }
        
        if(rem != 0)
            tmp->next = new ListNode(rem);
        
        return solution;
    }
};
