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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            // If the list is empty or has only one element, it is already reversed
            return head;
        }

        // Recursively reverse the rest of the list
        ListNode* reversedList = reverseList(head->next);

        // Adjust the next pointer of the current node
        head->next->next = head;
        head->next = nullptr;

        return reversedList;
    }
};
