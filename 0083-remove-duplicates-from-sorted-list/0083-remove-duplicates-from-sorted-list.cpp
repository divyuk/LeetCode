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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* forw = head->next;
        
        while(current and forw ){
            
            if(forw->val == current->val){
                current->next = forw->next;
            }
            else
                current = forw;
            forw= forw->next;
            
        }
        
        return head;
    }
};