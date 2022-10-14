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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prev = NULL; 
        ListNode* slow = head;
        ListNode* fast = head;
        if(slow->next==NULL)
            return NULL;
        while(slow){
            if(fast == NULL or fast->next == NULL){
                prev->next = slow->next;
                return head;
            }
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return head;
    }
};