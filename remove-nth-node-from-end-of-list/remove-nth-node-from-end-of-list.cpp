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
        ListNode *fast = head;
        ListNode *slow = head;
        
        // Move fast to n position and starts from there
        while(n--)
            fast = fast->next;
        
        // if the fast is at NULL that means its first region of destruction
        if(fast == NULL) return head->next;
        
        // Untill fast
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        
        slow->next=slow->next->next;
        
        return head;
        
    }
};