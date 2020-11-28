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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first = head;
        ListNode *second = head;
        
        for (int i = 1; i <= n + 1; i++) {
            if (first == NULL)
                return second->next;
            first = first->next;
        }

        while(first != NULL) {
            first = first->next;
            second = second->next;
        }

        second->next = second->next->next;

        return head;
    }
};
