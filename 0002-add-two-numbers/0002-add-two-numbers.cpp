class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr=l1;
        int carry=0;
        ListNode* node = new ListNode();
        ListNode* head = node;
        while(l1 and l2){

            int sum = l1->val+l2->val+carry;
            int s = sum%10;
            carry=sum/10;
            node->val = s;
            node->next = new ListNode();
            l1=l1->next;
            l2=l2->next;
            node=node->next;
        }

        while(l1){
            int sum = l1->val+0+carry;
            int s = sum%10;
            carry=sum/10;
            node->val = s;
            node->next = new ListNode();
            l1=l1->next;
            node=node->next;
        }
        while(l2){
            int sum = l2->val+0+carry;
            int s = sum%10;
            carry=sum/10;
            node->val = s;
            node->next = new ListNode();
            l2=l2->next;
            node=node->next;
        }
        if(carry){
            node->val = carry;
            node->next = new ListNode();
            node=node->next;
        }
        ListNode *r = NULL;
        ListNode *k = head;
        while(k->next){
            r=k;
            k=k->next;
        }
        r->next = NULL;
        return head;
    }
};