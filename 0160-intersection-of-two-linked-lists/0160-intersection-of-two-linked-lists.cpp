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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA){
            
            ListNode* checker  = headB; // address of headB
            
            while(checker){
                if(checker == headA) return checker;
            checker=checker->next;
            }
            
            
            headA=headA->next;
        }
        return NULL;
    }
};