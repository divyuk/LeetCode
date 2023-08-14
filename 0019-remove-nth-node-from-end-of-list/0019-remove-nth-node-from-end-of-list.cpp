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
        int size =0;
        ListNode *t = head;
        while(t){
            size++;
            t=t->next;
        }
        int del = size - n;
        int index=0;
        ListNode *prev = NULL;
        ListNode *curr=head;
        ListNode *forw = head->next;
        
        if(size==1) return NULL;
        if(del==0) return head->next;
        while(curr){
            
            
            if(index == del){
                prev->next = curr->next;
                break;
            }
            
            prev = curr;
            curr=curr->next;
            index++;
        }
        
        return head;
    }
};