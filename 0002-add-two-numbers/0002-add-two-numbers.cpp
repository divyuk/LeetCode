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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h = new ListNode();
        ListNode*head=h;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int sum=0;
        int carry =0;
        while(p1!=NULL and p2!=NULL){
            sum=p1->val + p2->val+carry; 
            carry=sum/10;
            sum=sum%10;
            h->val=sum;
            h->next=new ListNode();
            h = h->next;
            p1=p1->next;
            p2=p2->next;
            sum=0;
        }
        // cout<<carry;
        while(p1!=NULL){
            sum = p1->val+carry;
            carry = sum/10;
            sum = sum%10;
           
            
            
            // cout<<carry<<"\n";
            h->val=sum;
            h->next=new ListNode();
            h = h->next;
            p1=p1->next;    
            sum=0;
        }
        while(p2!=NULL){
            sum = p2->val+carry;
            carry = sum/10;
            sum = sum%10;
            h->val=sum;
            h->next=new ListNode();
            h = h->next;
            p2=p2->next; 
            sum=0;
        }
        cout<<carry;
        if(carry){
            h->val=carry;
            h->next=NULL;
        }
        else{
        ListNode* k = head->next;
        ListNode*  prev = head;
        
        while(k->next!=NULL){
            prev=k;
            k=k->next;
        
        }
        prev->next=NULL;
        }
        return head;
    }
};