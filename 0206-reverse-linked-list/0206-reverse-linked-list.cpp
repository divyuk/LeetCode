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
    ListNode* reverseList(ListNode* head) {
        if(!head or  !head->next) return head;
        ListNode* r = NULL;
        ListNode* p = head;
        ListNode* q = head->next;
        while(q and q->next){
            p->next =r;
             r = p;
             p = q;
            q= q->next;
        }
        p->next = r;
        q->next = p;
        return q;
    }
};