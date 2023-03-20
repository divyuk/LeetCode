class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* r = dummy;
        while (l1 and l2){
            if(l1->val <= l2->val){
                r->next = l1;
                l1=l1->next;
            }
            else{
                r->next=l2;
                l2=l2->next;
            }
            r=r->next;
        }

        while(l1){
            r->next=l1;
            l1=l1->next;
            r=r->next;
        }
        while(l2){
            r->next=l2;
            l2=l2->next;
            r=r->next;
        }
        return dummy->next;
    }
};