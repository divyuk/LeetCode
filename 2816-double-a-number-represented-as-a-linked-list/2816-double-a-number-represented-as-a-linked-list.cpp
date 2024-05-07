class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = nullptr;
        while (head) {
            ListNode* forw = head->next;
            head->next = newHead;
            newHead = head;
            head = forw;
        }
        return newHead;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* reversed = reverseList(head);
        ListNode* temp = reversed;
        ListNode* dummy = new ListNode();
        ListNode* dummyHead = dummy;
        int carry = 0;
        while (temp) {
            int val = (temp->val * 2) + carry;
            int digit = val % 10;
            carry = val / 10;
            dummy->next = new ListNode(digit);
            dummy = dummy->next;
            temp = temp->next;
        }
        // while (carry > 0) {
        //     dummy->next = new ListNode(carry % 10);
        //     carry /= 10;
        //     dummy = dummy->next;
        // }
        
        if(carry) dummy->next = new ListNode(carry);
        return reverseList(dummyHead->next);
    }
};
