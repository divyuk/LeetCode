class Solution {
public:
    
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* current = head;
        while(current != NULL){
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return;
        }
        
        // Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Split the list into two halves
        ListNode* secondHalf = slow->next;
        slow->next = NULL;
        
        // Reverse the second half
        secondHalf = reverse(secondHalf);
        
        // Merge the two halves
        ListNode* current = head;
        while(secondHalf != NULL){
            ListNode* temp1 = current->next;
            ListNode* temp2 = secondHalf->next;
            current->next = secondHalf;
            secondHalf->next = temp1;
            current = temp1;
            secondHalf = temp2;
        }
    }
};
