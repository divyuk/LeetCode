class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL and n==1) return NULL;
        
        int size=0,c=0;
        ListNode* temp = head;
        while(temp){
            size++;
            temp=temp->next;
        }
        int del = size-n;
        if(del==0) return head->next;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            if(c==del){
                prev->next = curr->next;
                break;
            }
            c++;
            prev=curr;
            curr=curr->next;

        }
        return head;
    }
};