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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *in = head;
        while(fast and fast->next){
            
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                while(in!=slow){
                    in=in->next;
                    slow=slow->next;
                }
                return in;
            }
        }
        return NULL;
    }
};