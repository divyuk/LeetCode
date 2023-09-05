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
    
    ListNode *reverse(ListNode *ptr){
        ListNode* pre=NULL;
        ListNode* nex=NULL;
        while(ptr!=NULL) {
            nex = ptr->next;
            ptr->next = pre;
            pre=ptr;
            ptr=nex;
        }
        return pre;
    }
    
    bool isPalindrome(ListNode* head) {
        // FInd Middle
        
        ListNode *slow=head;
        ListNode *fast = head;
        
        while(fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        // slow is pointing to middle
        
        // Reverse from middle->next to last
         slow->next = reverse(slow->next);
        
        // compare elements of head and middle->next
            slow = slow->next;
            ListNode* dummy = head;
        
        while(slow!=NULL) {
            if(dummy->val != slow->val) return false;
            dummy = dummy->next;
            slow = slow->next;
        }
        return true;
    }
};