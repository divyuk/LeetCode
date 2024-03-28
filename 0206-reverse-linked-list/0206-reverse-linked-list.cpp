class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case: If the list is empty or has only one node, return head
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Reverse the rest of the list recursively
        ListNode* newHead = reverseList(head->next);

        // Make the next node of the current head point to the current head
        head->next->next = head;

        // Set the next of current head to NULL to make it the new tail
        head->next = NULL;

        // Return the new head of the reversed list
        return newHead;
    }
};
