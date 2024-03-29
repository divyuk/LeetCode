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
    ListNode* removeElements(ListNode* head, int val) {
    
        while(head and head->val == val){
            head=head->next;
        }
        ListNode *curr = head;
        ListNode *last = NULL;
        ListNode *forw = NULL;
        while(curr){
            
            if(curr->val == val){
                last->next = curr->next;
            }
           
            else
                last =  curr;
            
            curr=curr->next;
            
        }
        return head;
    }
};