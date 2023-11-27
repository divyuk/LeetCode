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
ListNode* rotateRight(ListNode* head, int k) {
    if (!head || k == 0) {
        return head;
    }

    int size = 1; // Start from 1 because the head itself is a node.
    ListNode* temp = head;
    while (temp->next) {
        size++;
        temp = temp->next;
    }

    int distance = size - k % size;
    if (distance == size) // No rotation needed
        return head;
    

    // Find the new head and the new tail
    ListNode* newHead = head;
    for (int i = 1; i < distance; i++) {
        newHead = newHead->next;
    }

    ListNode* newTail = newHead;
    newHead = newHead->next;
    newTail->next = nullptr;

    // Update the pointers for rotation
    temp->next = head;

    return newHead;
}

};